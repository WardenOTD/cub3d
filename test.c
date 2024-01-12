#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	data.file = NULL;
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
	if (!validity(&data))
	{
		printf("validity error\n");
		return (2);
	}
	printf("\n===============================\n");
	printf("Floor color:: %s\n", data.f_color);
	printf("Ceiling color:: %s\n", data.c_color);
	printf("NO tex: %s\n", data.n_path);
	printf("EA tex: %s\n", data.e_path);
	printf("SO tex: %s\n", data.s_path);
	printf("WE tex: %s\n", data.w_path);
}
