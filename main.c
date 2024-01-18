#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	data.file = NULL;
	data.parse_check = 0;
	if (argc != 2)
		return (2);
	// data.mlx.mlx_ptr = mlx_init();
	// data.mlx.win_ptr = mlx_new_window(data.mlx.mlx_ptr, 500, 500, "cub3d");
	// mlx_string_put(data.mlx.mlx_ptr, data.mlx.win_ptr, 250, 250, 10200200, "string_put");
	// mlx_loop(data.mlx.mlx_ptr);
	if (!parse(&data, argv[1]))
	{
		printf("parse error\n");
		return (2);
	}
	for (int i = 0; data.file[i]; i++)
		printf("%s", data.file[i]);
	if (!validity(&data, 0, 0))
	{
		printf("validity error\n");
		return (2);
	}
	if (!color_check(&data))
	{
		printf("invalid color\n");
		return (2);
	}
	if (!map_valid(&data, 0, 0))
	{
		printf("invalid map\n");
		return (2);
	}
	if (!check_valid_path(&data))
		free_exit_msg(&data, 0, "Invalid texture path\n");
	printf("\n===============================\n");
	printf("NO tex: __%s__\n", data.n_path);
	printf("EA tex: __%s__\n", data.e_path);
	printf("SO tex: __%s__\n", data.s_path);
	printf("WE tex: __%s__\n", data.w_path);
	printf("Floor color:: __%s__\n", data.f_color);
	printf("Ceiling color:: __%s__\n", data.c_color);
	printf("Floor color hex:: %X\n", data.int_f_color);
	printf("Ceiling color hex:: %X\n", data.int_c_color);
	printf("map ::\n");
	for (int i = 0; data.map[i]; i++)
		printf("__%s__\n", data.map[i]);
	printf("Player facing: %c\n", data.ply_dir);

	//---ui stuff---
	data.game.mlx = mlx_init();
	data.game.win = mlx_new_window(data.game.mlx, H_RESOLUTION, V_RESOLUTION, "cub3d");
	init_all(&data.game, &data);
	mlx_loop_hook(data.game.mlx, render_next_frame, &data.game);
	mlx_loop(data.game.mlx);
}
int		render_next_frame(t_game *my_struct)
{
	t_game	*game;

	game = my_struct;
	game->frame.img_ptr = mlx_new_image(game->mlx,
			game->display.width, game->display.height);
	game->frame.data = (int *)mlx_get_data_addr(game->frame.img_ptr,
			&game->frame.bpp, &game->frame.size_l, &game->frame.endian);
	update(game);
	draw(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->frame.img_ptr);
	return (1);
}
