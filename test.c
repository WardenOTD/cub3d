#include "cub3d.h"

int	main()
{
	t_data	data;
	data.mlx.mlx_ptr = mlx_init();
	data.mlx.win_ptr = mlx_new_window(data.mlx.mlx_ptr, 500, 500, "cub3d");
	mlx_string_put(data.mlx.mlx_ptr, data.mlx.win_ptr, 250, 250, 10200200, "string_put");
	mlx_loop(data.mlx.mlx_ptr);
}
