#include "../cub3d.h"

int	check_valid_path(t_data *data)
{
	int    fd;

	fd = open(data->n_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(data->e_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(data->s_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(data->w_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
