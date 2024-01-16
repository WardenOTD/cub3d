/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nesw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:31:17 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/12 17:31:21 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_no(t_data *data, int i, int j)
{
	while (data->file[i][++j])
	{
		if (data->file[i][j] == ' ')
			continue ;
		if (data->file[i][j] == '.')
			return (get_tex_malloc(data, i, j, 'N'));
		else
			return (0);
	}
	return (0);
}

int	get_ea(t_data *data, int i, int j)
{
	while (data->file[i][++j])
	{
		if (data->file[i][j] == ' ')
			continue ;
		if (data->file[i][j] == '.')
			return (get_tex_malloc(data, i, j, 'E'));
		else
			return (0);
	}
	return (0);
}

int	get_so(t_data *data, int i, int j)
{
	while (data->file[i][++j])
	{
		if (data->file[i][j] == ' ')
			continue ;
		if (data->file[i][j] == '.')
			return (get_tex_malloc(data, i, j, 'S'));
		else
			return (0);
	}
	return (0);
}

int	get_we(t_data *data, int i, int j)
{
	while (data->file[i][++j])
	{
		if (data->file[i][j] == ' ')
			continue ;
		if (data->file[i][j] == '.')
			return (get_tex_malloc(data, i, j, 'W'));
		else
			return (0);
	}
	return (0);
}
