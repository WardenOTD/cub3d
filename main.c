/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:41:24 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 17:04:02 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->file = NULL;
	data->map = NULL;
	data->n_path = NULL;
	data->e_path = NULL;
	data->s_path = NULL;
	data->w_path = NULL;
	data->c_color = NULL;
	data->f_color = NULL;
	data->parse_check = 0;
}

void	err(t_data *data, char *file)
{
	if (!file_extension(file))
		free_exit_msg(data, 0, "invalid file extension\n");
	if (!check_file_exist(file))
		free_exit_msg(data, 0, "invalid file: file does not exist\n");
	if (!parse(data, file))
		free_exit_msg(data, 0, "file read failed\n");
	if (!validity(data, 0, 0))
		free_exit_msg(data, 0, "invalid file structure: element definition\n");
	if (!color_check(data))
		free_exit_msg(data, 0, "invalid colors: 0-255 :: RRR,GGG,BBB\n");
	if (!map_valid(data, 0, 0))
		free_exit_msg(data, 0, "invalid map\n");
	if (!check_valid_path(data))
		free_exit_msg(data, 0, "invalid texture path\n");
}

void	debug_print(t_data *data)
{
	int	i;

	i = 0;
	printf("\n===============================\n");
	printf("NO tex: __%s__\n", data->n_path);
	printf("EA tex: __%s__\n", data->e_path);
	printf("SO tex: __%s__\n", data->s_path);
	printf("WE tex: __%s__\n", data->w_path);
	printf("Floor color:: __%s__\n", data->f_color);
	printf("Ceiling color:: __%s__\n", data->c_color);
	printf("Floor color hex:: %X\n", data->int_f_color);
	printf("Ceiling color hex:: %X\n", data->int_c_color);
	printf("map ::\n");
	while (data->map[i])
		printf("__%s__\n", data->map[i++]);
	printf("Player facing: %c\n", data->ply_dir);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (2);
	init_data(&data);
	err(&data, argv[1]);
	debug_print(&data);
	data.game.mlx = mlx_init();
	data.game.win = mlx_new_window(data.game.mlx,
			H_RESOLUTION, V_RESOLUTION, "cub3d");
	init_all(&data.game, &data);
	mlx_loop_hook(data.game.mlx, render_next_frame, &data);
	mlx_loop(data.game.mlx);
	return (0);
}

int	render_next_frame(t_data *data)
{
	t_game	*game;

	game = &data->game;
	game->frame.img_ptr = mlx_new_image(game->mlx,
			game->display.width, game->display.height);
	game->frame.data = (int *)mlx_get_data_addr(game->frame.img_ptr,
			&game->frame.bpp, &game->frame.size_l, &game->frame.endian);
	update(game);
	draw(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img_ptr, 0, 0);
	put_sprite(game);
	render_minimap(data);
	mlx_destroy_image(game->mlx, game->frame.img_ptr);
	return (1);
}
