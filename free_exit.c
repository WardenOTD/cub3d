/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:41:14 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 10:55:00 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_exit_msg(t_data *data, int code, char *msg)
{
	printf("%s", msg);
	free_exit(data, code);
}

void	free_exit(t_data *data, int code)
{
	if (data->file)
		free2d(data->file);
	if (data->map)
		free2d(data->map);
	if (data->n_path)
		free(data->n_path);
	if (data->e_path)
		free(data->e_path);
	if (data->s_path)
		free(data->s_path);
	if (data->w_path)
		free(data->w_path);
	if (data->c_color)
		free(data->c_color);
	if (data->f_color)
		free(data->f_color);
	if (code == 1)
		free(data->game.rays.arr);
	exit (1);
}

void	free2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
