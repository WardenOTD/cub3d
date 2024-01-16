/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:07:09 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/16 13:34:48 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_c(t_data *data, int i, int j)
{
	while (data->file[i][++j])
	{
		if (ft_isalpha(data->file[i][j]))
			return (0);
		if (data->file[i][j] == ' ')
			continue ;
		if (ft_isdigit(data->file[i][j]))
			return (get_c_malloc(data, i, j, 0));
		else
			return (0);
	}
	return (0);
}

int	get_c_malloc(t_data *data, int i, int j, int pos)
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
	get_c_copy(data, i, pos, index);
	return (1);
}

void	get_c_copy(t_data *data, int i, int j, int index)
{
	int	k;

	data->c_color = (char *)malloc(sizeof(char) * (index + 1));
	data->c_color[index] = 0;
	k = 0;
	while (k < index)
		data->c_color[k++] = data->file[i][j++];
}
