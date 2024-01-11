#include "cub3d.h"

int	main()
{
	t_data	data;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "cub3d");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 250, 250, 10200200, "string_put");
	mlx_loop(data.mlx_ptr);
}
