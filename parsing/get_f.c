/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:06:35 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/12 18:56:25 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_f(t_data *data, int i, int j)
{
	while (data->file[i][++j])
	{
		if (ft_isalpha(data->file[i][j]))
			return (0);
		if (data->file[i][j] == ' ')
			continue ;
		if (ft_isdigit(data->file[i][j]))
			return (get_f_malloc(data, i, j, 0));
		else
			return (0);
	}
	return (0);
}

int	get_f_malloc(t_data *data, int i, int j, int pos)
{
	int	nflag[2];
	int	cflag;
	int	index;
	int	valid;

	get_malloc_init(nflag, &cflag, &index);
	while (data->file[i][j])
	{
		valid = validity_flag_set(nflag, &cflag, data->file[i][j]);
		if (!valid)
			return (0);
		else if (valid == 2)
			break ;
		if (ft_isdigit(data->file[i][j]) || data->file[i][j] == ',')
		{
			index++;
			if (pos == 0)
				pos = j;
		}
		j++;
	}
	if (!check_invalid_after(data, i, j))
		return (0);
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
		data->f_color[k++] = data->file[i][j++];
}

void	get_malloc_init(int *nflag, int *cflag, int *index)
{
	nflag[0] = 0;
	nflag[1] = 0;
	*cflag = 0;
	*index = 0;
}

int	validity_flag_set(int *nflag, int *cflag, char cur)
{
	if (ft_isdigit(cur))
	{
		nflag[1] += 1;
		if (nflag[1] > 3)
			return (0);
		if (nflag[0] == *cflag)
			nflag[0] += 1;
	}
	if (cur == ',')
	{
		nflag[1] = 0;
		if (nflag[0] > *cflag)
			*cflag += 1;
		else
			return (0);
	}
	if (cur == ' ')
	{
		if (nflag[0] > 0 && nflag[0] < 3)
			return (0);
		if (nflag[0] == 3)
			return (2);
	}
	return (1);
}
