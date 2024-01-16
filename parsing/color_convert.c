/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:24:24 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/16 12:09:56 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_check(t_data *data)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (data->c_color[i])
	{
		tmp += (data->c_color[i] - '0');
		i++;
		if (data->c_color[i] == ',' || data->c_color[i] == 0)
		{
			if (tmp > 255)
				return (0);
			tmp = 0;
			if (data->c_color[i] == ',')
				i++;
			continue ;
		}
		tmp *= 10;
	}
	return (color_check2(data));
}

int	color_check2(t_data *data)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (data->f_color[i])
	{
		tmp += (data->f_color[i] - '0');
		i++;
		if (data->f_color[i] == ',' || data->f_color[i] == 0)
		{
			if (tmp > 255)
				return (0);
			tmp = 0;
			if (data->f_color[i] == ',')
				i++;
			continue ;
		}
		tmp *= 10;
	}
	color_convert(data, 0, 0, 0);
	return (1);
}

void	color_convert(t_data *data, int r, int g, int b)
{
	int	i;

	i = 0;
	r = convert_r(data, 0, 0);
	g = convert_g(data, 0, 0);
	b = convert_b(data, 0, 2);
	data->int_c_color = ((r << 16) | (g << 8) | b);
	r = convert_r(data, 0, 1);
	g = convert_g(data, 0, 1);
	b = convert_b(data, 0, 3);
	data->int_f_color = ((r << 16) | (g << 8) | b);
}
