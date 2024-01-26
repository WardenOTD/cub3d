/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:39:51 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 10:40:04 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update_player_position(t_player *player, char **grid)
{
	double	move_step;
	double	rotation;

	if (player->walk_direction == 0)
		return ;
	move_step = player->move_speed;
	rotation = player->rotation_angle;
	if (player->walk_direction == 's')
		move_step = (-1) * player->move_speed;
	else if (player->walk_direction == 'a')
	{
		move_step = (-1) * player->move_speed;
		rotation = player->rotation_angle + deg_to_rad(90);
	}
	else if (player->walk_direction == 'd')
		rotation = player->rotation_angle + deg_to_rad(90);
	player->x += cos(rotation) * move_step;
	player->y += sin(rotation) * move_step;
	if (ft_strchr("12", grid[(int)player->y][(int)player->x]))
	{
		player->x -= cos(rotation) * move_step;
		player->y -= sin(rotation) * move_step;
	}
}

void	update_player_orientation(t_player *player)
{
	double	rotation;

	if (player->turn_direction == 0)
		return ;
	rotation = player->turn_direction * player->rotation_speed;
	player->rotation_angle += rotation;
}

void	raycasting(t_game *game)
{
	double	ray_angle;
	int		i;

	ray_angle = game->player.rotation_angle - game->rays.view_angle / 2;
	i = 0;
	while (i < game->display.width)
	{
		game->rays.arr[i].angle = ray_angle;
		cast_single_ray(&game->rays.arr[i], &game->display.map, &game->player);
		ray_angle += game->rays.view_angle / game->display.width;
		i++;
	}
}

void	update(t_game *game)
{
	update_player_position(&game->player, game->display.map.map);
	update_player_orientation(&game->player);
	raycasting(game);
}
