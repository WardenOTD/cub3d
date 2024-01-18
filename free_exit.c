#include "cub3d.h"

void	free_exit_msg(t_data *data, int code, char *msg)
{
	printf("%s", msg);
	free_exit(data, code);
}

void	free_exit(t_data *data, int code)
{
	free2d(data->map);
	free2d(data->file);
	free(data->n_path);
	free(data->s_path);
	free(data->e_path);
	free(data->w_path);
	free(data->c_color);
	free(data->f_color);
	if (code == 1)
		free(data->game.rays.arr);
	exit (0);
}

void	free2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
