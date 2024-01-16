/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:51:44 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/16 12:09:38 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_r(t_data *data, int i, int mod)
{
	int	ret;

	ret = 0;
	if (mod == 0)
	{
		while (data->c_color[i] && data->c_color[i] != ',')
		{
			ret += (data->c_color[i] - '0');
			i++;
			if (data->c_color[i] != ',')
				ret *= 10;
		}
	}
	else if (mod == 1)
	{
		while (data->f_color[i] && data->f_color[i] != ',')
		{
			ret += (data->f_color[i] - '0');
			i++;
			if (data->f_color[i] != ',')
				ret *= 10;
		}
	}
	return (ret);
}

int	convert_g(t_data *data, int i, int mod)
{
	int	ret;

	ret = 0;
	i = go_next_val(data, mod);
	if (mod == 0)
	{
		while (data->c_color[i] && data->c_color[i] != ',')
		{
			ret += (data->c_color[i] - '0');
			i++;
			if (data->c_color[i] != ',')
				ret *= 10;
		}
	}
	else if (mod == 1)
	{
		while (data->f_color[i] && data->f_color[i] != ',')
		{
			ret += (data->f_color[i] - '0');
			i++;
			if (data->f_color[i] != ',')
				ret *= 10;
		}
	}
	return (ret);
}

int	convert_b(t_data *data, int i, int mod)
{
	int	ret;

	ret = 0;
	i = go_next_val(data, mod);
	if (mod == 2)
	{
		while (data->c_color[i])
		{
			ret += (data->c_color[i] - '0');
			i++;
			if (data->c_color[i] != 0)
				ret *= 10;
		}
	}
	else if (mod == 3)
	{
		while (data->f_color[i])
		{
			ret += (data->f_color[i] - '0');
			i++;
			if (data->f_color[i] != 0)
				ret *= 10;
		}
	}
	return (ret);
}

int	go_next_val(t_data *data, int mod)
{
	int	i;

	i = 0;
	if (mod == 0)
		while (data->c_color[i] != ',')
			i++;
	if (mod == 1)
		while (data->f_color[i] != ',')
			i++;
	if (mod == 2)
		while (data->c_color[i] != ',')
			i++;
	if (mod == 3)
		while (data->f_color[i] != ',')
			i++;
	if (mod == 2 || mod == 3)
		i++;
	if (mod == 2)
		while (data->c_color[i] != ',')
			i++;
	if (mod == 3)
		while (data->f_color[i] != ',')
			i++;
	return (i + 1);
}
