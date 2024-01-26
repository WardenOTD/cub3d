/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:41:20 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 10:45:18 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->game.player.walk_direction = 'w';
	else if (keycode == KEY_A)
		data->game.player.walk_direction = 'a';
	else if (keycode == KEY_S)
		data->game.player.walk_direction = 's';
	else if (keycode == KEY_D)
		data->game.player.walk_direction = 'd';
	else if (keycode == KEY_L_ARROW)
		data->game.player.turn_direction = -1;
	else if (keycode == KEY_R_ARROW)
		data->game.player.turn_direction = 1;
	else if (keycode == KEY_ESC)
		free_exit(data, 1);
	else if (keycode == KEY_F)
		data->game.activate_mouse *= -1;
	return (1);
}

int	key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		game->player.walk_direction = 0;
	else if (keycode == KEY_L_ARROW || keycode == KEY_R_ARROW)
		game->player.turn_direction = 0;
	return (1);
}

int	close_window(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	exit(0);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	screen_centre = H_RESOLUTION / 2;

	(void)y;
	if (game->activate_mouse > 0)
		return (0);
	if (x == screen_centre)
		game->player.turn_direction = 0;
	else if (x < screen_centre)
		game->player.turn_direction = -1;
	else if (x > screen_centre)
		game->player.turn_direction = 1;
	screen_centre = x;
	mlx_mouse_move(game->win, H_RESOLUTION / 2, V_RESOLUTION / 2);
	return (0);
}

// int	mouse_move(int x, int y, t_game *game)
// {
// 	static int	screen_centre = H_RESOLUTION / 2;

// 	(void)y;
// 	if (game->activate_mouse > 0)
// 		return (0);
// 	if (x == screen_centre)
// 		game->player.turn_direction = 0;
// 	else if (x < screen_centre)
// 		game->player.turn_direction = -1;
// 	else if (x > screen_centre)
// 		game->player.turn_direction = 1;
// 	screen_centre = x;
// 	mlx_mouse_move(game->mlx, game->win,
// 		H_RESOLUTION / 2, V_RESOLUTION / 2);
// 	return (0);
// }
