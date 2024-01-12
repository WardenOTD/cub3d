/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:17:17 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/12 12:13:42 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse(t_data *data, char *argv)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 1);
	tmp[0] = 'a';
	fd = open(argv, O_RDONLY | O_EXCL);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (check_line_empty(tmp) == 0)
			continue ;
		else if (check_line_empty(tmp) == 2)
			break ;
		else
		{
			realloc2d(data, i + 1);
			data->map[i] = ft_strdup(tmp);
			i++;
		}
	}
	close(fd);
	return (1);
}

int	check_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (2);
	while (line[i])
	{
		if (line[i] != '\n' && line[i] != ' ')
			return (1);
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (0);
}

void	realloc2d(t_data *data, int size)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (size + 1));
	copy[size] = NULL;
	if (data->map)
	{
		while (data->map[i])
		{
			copy[i] = ft_strdup(data->map[i]);
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	data->map = copy;
}

int	validity(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_isdigit(data->map[i][j]))
				return (0);
			if (ft_strncmp(&(data->map[i][j]), "F", 1))
				if (!get_f(data, i , j))
					return (0);
			// else if (ft_strncmp(&(data->map[i][j]), "C", 1))
			// 	//
			// else if (ft_strncmp(&(data->map[i][j]), "NO", 2))
			// 	//
			// else if (ft_strncmp(&(data->map[i][j]), "EA", 2))
			// 	//
			// else if (ft_strncmp(&(data->map[i][j]), "SO", 2))
			// 	//
			// else if (ft_strncmp(&(data->map[i][j]), "WE", 2))
			// 	//
			j++;
		}
		i++;
	}
	return (1);
}

int	get_f(t_data *data, int i, int j)
{
	while (data->map[i][++j])
	{
		if (ft_isalpha(data->map[i][j]))
			return (0);
		if (data->map[i][j] == ' ')
			continue ;
		if (ft_isdigit(data->map[i][j]))
			return (get_f_malloc(data, i, j));
		else
			return (0);
	}
	return (0);
}

int	get_f_malloc(t_data *data, int i, int j)
{
	int	*nflag;
	int	cflag;
	int	index;
	int	pos;

	pos = 0;
	get_f_malloc_init(&nflag, &cflag, &index);
	while (data->map[i][j])
	{
		if (!validity_flag_set(&nflag, &cflag, data->map[i][j]))
			return (0);
		if (ft_isdigit(data->map[i][j]) || data->map[i][j] == ',')
		{
			index++;
			if (pos == 0)
				pos = j;
		}
	}
	get_f_copy(data, i, pos, index);
	return (1);
}

void	get_f_copy(t_data *data, int i, int j, int index)
{
	int	k;

	data->f_color = (char *)malloc(sizeof(char) * (index + 1));
	data->f_color[index] = 0;
	k = 0;
	while (k < index)
		data->f_color[k++] = data->map[i][j++];
}

void	get_f_malloc_init(int **nflag, int *cflag, int *index)
{
	*nflag[0] = 0;
	*nflag[1] = 0;
	*cflag = 0;
	*index = 0;
}

int	validity_flag_set(int **nflag, int *cflag, char cur)
{
	if (ft_isdigit(cur))
	{
		*nflag[1] += 1;
		if (*nflag[1] > 3)
			return (0);
		if (*nflag[0] == *cflag)
			*nflag[0] += 1;
	}
	if (cur == ',')
	{
		*nflag[1] = 0;
		if (*nflag[0] > *cflag)
			*cflag += 1;
		else
			return (0);
	}
	if (cur == ' ')
	{
		if (*nflag[0] != 0)
			return (0);
	}
	return (1);
}
