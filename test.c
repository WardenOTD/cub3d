#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (2);
	// data.mlx.mlx_ptr = mlx_init();
	// data.mlx.win_ptr = mlx_new_window(data.mlx.mlx_ptr, 500, 500, "cub3d");
	// mlx_string_put(data.mlx.mlx_ptr, data.mlx.win_ptr, 250, 250, 10200200, "string_put");
	// mlx_loop(data.mlx.mlx_ptr);
	parse(&data, argv[1]);
	for (int i = 0; data.map[i]; i++)
		printf("%s", data.map[i]);
	validity(&data);
	printf("Floor color:: %s\n", data.f_color);
}
