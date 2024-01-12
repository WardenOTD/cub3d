/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:17:17 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/12 17:27:40 by jteoh            ###   ########.fr       */
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
			data->file[i] = ft_strdup(tmp);
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
	if (data->file)
	{
		while (data->file[i])
		{
			copy[i] = ft_strdup(data->file[i]);
			free(data->file[i]);
			i++;
		}
		free(data->file);
	}
	data->file = copy;
}
