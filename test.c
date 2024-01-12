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
	printf("\n===============================\n");
	printf("NO tex: __%s__\n", data.n_path);
	printf("EA tex: __%s__\n", data.e_path);
	printf("SO tex: __%s__\n", data.s_path);
	printf("WE tex: __%s__\n", data.w_path);
	printf("Floor color:: __%s__\n", data.f_color);
	printf("Ceiling color:: __%s__\n", data.c_color);
}
