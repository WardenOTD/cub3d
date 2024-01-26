/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:51:01 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 17:11:07 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_ratio(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j])
		j++;
	while (data->map[i])
		i++;
	if (i > j)
		return (350 / i);
	else
		return (400 / j);
}

void	render_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->size = map_ratio(data);
	if (data->size % 2 == 0)
		data->size++;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			detect_block(data, i, j);
			j++;
		}
		i++;
	}
	place_block(data, data->game.player.y, data->game.player.x,
		rgb(162, 166, 58));
}

void	detect_block(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0')
		place_block(data, i, j, rgb(116, 166, 219));
	if (data->map[i][j] == '1')
		place_block(data, i, j, rgb(26, 26, 61));
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
		place_block(data, i, j, rgb(116, 166, 219));
	if (data->map[i][j] == ' ')
		place_block(data, i, j, rgb(100, 100, 100));
}

void	place_block(t_data *data, int i, int j, int color)
{
	int	x;
	int	y;
	int	t;
	int	tt;

	i++;
	j++;
	y = i * data->size;
	t = data->size;
	while (t > 0)
	{
		tt = data->size;
		x = j * data->size;
		while (tt > 0)
		{
			mlx_pixel_put(data->game.mlx, data->game.win, x, y, color);
			x--;
			tt--;
		}
		y--;
		t--;
	}
}
