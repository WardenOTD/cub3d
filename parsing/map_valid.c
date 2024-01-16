/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:15:03 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/16 11:11:48 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_valid(t_data *data, int i, int j)
{
	int	pcount;

	pcount = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
			{
				data->ply_dir = data->map[i][j];
				pcount++;
			}
			j++;
		}
		i++;
	}
	if (pcount != 1)
		return (0);
	return (map_check_perimeter(data, 0, 0, 0));
}

int	map_check_perimeter(t_data *data, int i, int j, int mod)
{
	while (data->map[i][j])
	{
		if (data->map[i][j] != ' ' && data->map[i][j] != '1')
			return (0);
		j++;
	}
	if (mod == 0)
	{
		while (data->map[i])
			i++;
		--i;
		return (map_check_perimeter(data, i, 0, 1));
	}
	return (map_check_perimeter2(data, 0, 0, 0));
}

int	map_check_perimeter2(t_data *data, int i, int j, int mod)
{
	int	sav;

	sav = j;
	while (data->map[i])
	{
		j = sav;
		while (data->map[i][j] && j >= 0)
		{
			if (data->map[i][j] == '1')
				break ;
			else if (data->map[i][j] != '1' && data->map[i][j] != ' ')
				return (0);
			if (mod == 0)
				j++;
			else if (mod == 1)
				j--;
		}
		i++;
	}
	if (mod == 0)
		return (map_check_perimeter2(data, 0,
				(ft_strlen(data->map[0]) - 1), 1));
	return (map_check_void(data, 0, 0));
}

int	map_check_void(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' '
					|| data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
