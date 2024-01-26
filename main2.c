/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:03:27 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 17:04:59 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sprite(t_game *game)
{
	if (game->change_sprite > 0)
	{
		game->display.pov.img_ptr = mlx_xpm_file_to_image(game->mlx,
				"./textures/knife.xpm", &game->display.pov.width,
				&game->display.pov.height);
		mlx_put_image_to_window(game->mlx, game->win, game->display.pov.img_ptr,
			400, 440);
	}
	else
	{
		game->display.pov.img_ptr = mlx_xpm_file_to_image(game->mlx,
				"./textures/gun.xpm", &game->display.pov.width,
				&game->display.pov.height);
		mlx_put_image_to_window(game->mlx, game->win, game->display.pov.img_ptr,
			700, 440);
	}
	mlx_destroy_image(game->mlx, game->display.pov.img_ptr);
}
