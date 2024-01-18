#include "cub3d.h"

int		key_pressed(int keycode, t_data *data)
{
	// printf("%d\n", keycode);
	if (keycode == KEY_W)
		data->game.player.walk_direction = 'w';
	else if (keycode == KEY_A)
		data->game.player.walk_direction = 'a';
	else if (keycode == KEY_S)
		data->game.player.walk_direction = 's';
	else if (keycode == KEY_D)
		data->game.player.walk_direction = 'd';
	else if (keycode == KEY_L_ARROW)
		data->game.player.turn_direction = -1;
	else if (keycode == KEY_R_ARROW)
		data->game.player.turn_direction = 1;
	else if (keycode == KEY_ESC)
		free_exit(data, 1);
	return (1);
}

int		key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		game->player.walk_direction = 0;
	else if (keycode == KEY_L_ARROW || keycode == KEY_R_ARROW)
		game->player.turn_direction = 0;
	return (1);
}
