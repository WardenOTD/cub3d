#include "cub3d.h"

int	main()
{
	t_data	data;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "cub3d");
	mlx_string_put(data.mlx, data.win, 250, 250, 10200200, "string_put");
	mlx_loop(data.mlx);
}