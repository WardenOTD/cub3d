/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:40:30 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/15 18:06:12 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map(t_data *data, int i)
{
	int	j;
	int	index;
	int	pos;

	index = 0;
	pos = i;
	while (data->file[i])
	{
		j = 0;
		if (check_invalid_after(data, i, j))
			break ;
		while (data->file[i][j])
		{
			if (data->file[i][j] == '\n')
				break ;
			if (check_map_items(data->file[i][j]))
				j++;
			else
				return (0);
		}
		i++;
		index++;
	}
	return (map_2d_malloc(data, pos, index));
}

int	check_map_items(char c)
{
	if (c != ' ')
		if (c != '0' && c != '1')
			if (c != 'N' && c != 'E' && c != 'S' && c != 'W')
				return (0);
	return (1);
}

int	map_2d_malloc(t_data *data, int pos, int index)
{
	int	i;

	i = 0;
	data->map = (char **)malloc(sizeof(char *) * (index + 1));
	data->map[index] = NULL;
	while (index > 0)
	{
		if (!map_1d_malloc(data, pos, 0, i))
			return (0);
		i++;
		pos++;
		index--;
	}
	map_clean(data);
	return (1);
}

int	map_1d_malloc(t_data *data, int pos, int j, int i)
{
	int	index;

	index = 0;
	while (data->file[pos][j])
	{
		if (data->file[pos][j] == '\n')
			break ;
		if (check_map_items(data->file[pos][j]))
			j++;
		else
			return (0);
	}
	data->map[i] = (char *)malloc(sizeof(char) * (j + 1));
	data->map[i][j] = 0;
	return (map_1d_copy(data, pos, i));
}

int	map_1d_copy(t_data *data, int pos, int i)
{
	int	j;

	j = 0;
	while (data->file[pos][j] && data->file[pos][j] != '\n')
	{
		data->map[i][j] = data->file[pos][j];
		j++;
	}
	return (1);
}
