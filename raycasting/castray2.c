/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castray2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:39:18 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 10:39:38 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_v_intersection_w(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_x = floor(player->x);
	x_step = player->x - a_x;
	y_step = x_step * tan(ray->angle);
	a_y = player->y - y_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x - 1, a_y, ray))
		return ;
	x_step = -1;
	y_step = x_step * tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x - 1, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}

void	find_v_intersection_e(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_x = ceil(player->x);
	x_step = a_x - player->x;
	y_step = x_step * tan(ray->angle);
	a_y = player->y + y_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x, a_y, ray))
		return ;
	x_step = 1;
	y_step = x_step * tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}

void	find_h_intersection(t_ray *ray, t_map *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_to_rad(180) || ray->angle == deg_to_rad(360))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (0 <= ray->angle && ray->angle < PI)
		find_h_intersection_s(ray, map, player);
	else
		find_h_intersection_n(ray, map, player);
}

void	find_v_intersection(t_ray *ray, t_map *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_to_rad(90) || ray->angle == deg_to_rad(270))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (PI / 2 <= ray->angle && ray->angle < PI * 1.5)
		find_v_intersection_w(ray, map, player);
	else
		find_v_intersection_e(ray, map, player);
}

void	cast_single_ray(t_ray *ray, t_map *map, t_player *player)
{
	t_ray	find_h;
	t_ray	find_v;

	find_h.angle = normalize_radian(ray->angle);
	find_v.angle = normalize_radian(ray->angle);
	find_h.side = 'H';
	find_v.side = 'V';
	find_h_intersection(&find_h, map, player);
	find_v_intersection(&find_v, map, player);
	if (find_h.size <= find_v.size)
		*ray = find_h;
	else
		*ray = find_v;
}
