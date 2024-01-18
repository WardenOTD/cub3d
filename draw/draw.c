#include "../cub3d.h"

void	draw_rect(t_rect *rect, int *img, int res_width)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	rect->border_width--;
	i = -1;
	while (++i < rect->height)
	{
		j = -1;
		while (++j < rect->width)
		{
			tmp_x = rect->x + j;
			tmp_y = rect->y + i;
			if (i <= rect->border_width || j <= rect->border_width
				|| i >= rect->height - 1 - rect->border_width
				|| j >= rect->width - 1 - rect->border_width)
				img[tmp_y * res_width + tmp_x] = rect->border_color;
			else
				img[tmp_y * res_width + tmp_x] = rect->fill_color;
		}
	}
}

void	draw_ceilling(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = game->display.width;
	rect.height = game->display.height / 2;
	rect.border_width = 0;
	rect.fill_color = game->display.ceilling;
	draw_rect(&rect, game->frame.data, game->display.width);
}

void	draw_floor(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = game->display.height / 2;
	rect.width = game->display.width;
	rect.height = game->display.height / 2;
	rect.border_width = 0;
	rect.fill_color = game->display.floor;
	draw_rect(&rect, game->frame.data, game->display.width);
}

t_texture	get_wall_texture(t_display *display, char orientation)
{
	if (orientation == 'N')
		return (display->no_tex);
	else if (orientation == 'S')
		return (display->so_tex);
	else if (orientation == 'E')
		return (display->ea_tex);
	else
		return (display->we_tex);
}

double		get_wall_height(t_game *game, t_ray *ray)
{
	double	wall_height;
	double	scaled_distance;
	double	fisheye_adjustment;

	fisheye_adjustment = cos(ray->angle - game->player.rotation_angle);
	scaled_distance = ray->size * SCALE * fisheye_adjustment;
	wall_height = (SCALE / (scaled_distance)) * game->rays.dist_proj_plane;
	return (wall_height);
}

int			get_y_wall_position(t_game *game, double wall_height)
{
	double	center_screen;
	double	center_wall;
	int		y;

	center_screen = game->display.height / 2;
	center_wall = wall_height / 2;
	y = center_screen - center_wall;
	if (y < 0)
		y = 0;
	return (y);
}

int		get_bitmap_offset(t_ray *ray, int bitmap_width)
{
	double	remainder;
	int		offset;

	if (ray->side == 'H')
	{
		remainder = ray->x - floor(ray->x);
		offset = bitmap_width * remainder;
	}
	else
	{
		remainder = ray->y - floor(ray->y);
		offset = bitmap_width * remainder;
	}
	return (offset);
}

void	draw_wall_strip(t_rect *rect, int *img, t_display *display, t_ray *ray)
{
	int		y;
	int		y_tex;
	int		x_tex;
	double	step;
	double	tex_pox;

	step = 1.0 * rect->tex.height / rect->height;
	tex_pox = (rect->y - display->height / 2 + rect->height / 2) * step;
	x_tex = get_bitmap_offset(ray, rect->tex.width);
	y = -1;
	while (++y < rect->height && y < display->height)
	{
		y_tex = (int)tex_pox & (rect->tex.height - 1);
		tex_pox += step;
		img[(rect->y * display->width) + (y * display->width)
			+ rect->x] = rect->tex.data[y_tex * rect->tex.height + x_tex];
	}
}

void		draw_walls(t_game *game)
{
	int		i;
	double	wall_height;
	t_rect	rect;
	t_ray	*ray;

	i = -1;
	while (++i < game->display.width)
	{
		ray = &game->rays.arr[i];
		wall_height = get_wall_height(game, ray);
		rect.x = i;
		rect.y = get_y_wall_position(game, wall_height);
		rect.height = wall_height;
		rect.tex = get_wall_texture(&game->display, ray->orientation);
		draw_wall_strip(&rect, game->frame.data, &game->display, ray);
	}
}

void	draw(t_game *game)
{
	draw_ceilling(game);
	draw_floor(game);
	draw_walls(game);
}