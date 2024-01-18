#include "cub3d.h"

void	init_display_params(t_game *game, t_data *data)
{
	game->display.map.map = data->map;
	game->display.width = H_RESOLUTION;
	game->display.height = V_RESOLUTION;
	game->rays.view_angle = FOV_ANGLE;
	game->display.map.height = get_map_height(data->map);
	game->display.map.width = get_map_width(data->map);
	game->display.ceilling = data->int_c_color;
	game->display.floor = data->int_f_color;
}

void	init_player_params(t_game *game, t_data *data)
{
	game->player.walk_direction = 0;
	game->player.move_speed = 0.05;
	game->player.turn_direction = 0;
	game->player.rotation_speed = deg_to_rad(3);
	get_player_pos(game->display.map.map, &game->player.x, &game->player.y);
	game->player.rotation_angle = deg_to_rad(get_player_dir(data->ply_dir));
}

void	init_ray_params(t_game *game)
{
	game->rays.arr = malloc(2 * H_RESOLUTION * sizeof(t_ray));
	if (!game->rays.arr)
		exit(EXIT_SUCCESS);
	game->rays.view_angle = deg_to_rad(FOV_ANGLE);
	game->rays.dist_proj_plane = (game->display.width / 2)
		/ tan(game->rays.view_angle / 2);
}

void	init_textures(void *mlx, t_display *display)
{
	display->no_tex.img_ptr = mlx_xpm_file_to_image(mlx, "./textures/north.xpm",
		&display->no_tex.width, &display->no_tex.height);
	display->no_tex.data = (int *)mlx_get_data_addr(display->no_tex.img_ptr,
		&display->no_tex.bpp, &display->no_tex.size_l, &display->no_tex.endian);

	display->so_tex.img_ptr = mlx_xpm_file_to_image(mlx, "./textures/south.xpm",
		&display->so_tex.width, &display->so_tex.height);
	display->so_tex.data = (int *)mlx_get_data_addr(display->so_tex.img_ptr,
		&display->so_tex.bpp, &display->so_tex.size_l, &display->so_tex.endian);
			
	display->ea_tex.img_ptr = mlx_xpm_file_to_image(mlx, "./textures/east.xpm",
		&display->ea_tex.width, &display->ea_tex.height);
	display->ea_tex.data = (int *)mlx_get_data_addr(display->ea_tex.img_ptr,
		&display->ea_tex.bpp, &display->ea_tex.size_l, &display->ea_tex.endian);
	
	display->we_tex.img_ptr = mlx_xpm_file_to_image(mlx, "./textures/west.xpm",
		&display->we_tex.width, &display->we_tex.height);
	display->we_tex.data = (int *)mlx_get_data_addr(display->we_tex.img_ptr,
		&display->we_tex.bpp, &display->we_tex.size_l, &display->we_tex.endian);
}

void init_all(t_game *game, t_data *data)
{
	init_display_params(game, data);
	init_player_params(game, data);
	mlx_hook(game->win, KEY_PRESS, M_KEY_PRESS, key_pressed, game);
	mlx_hook(game->win, KEY_RELEASE, M_KEY_RELEASE, key_released, game);
	init_ray_params(game);
	init_textures(game->mlx, &game->display);
}
