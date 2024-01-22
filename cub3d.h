/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:57:42 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/22 16:12:15 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "structs.h"
# include "constants.h"

# if __linux__
#  include <X11/X.h>
#  include "mlx_linux/mlx.h"
# else
#  include <mlx.h>
# endif

//--------parsing--------
//---get_file.c---
int		parse(t_data *data, char *argv);
int		check_line_empty(char *line);
void	realloc2d(t_data *data, int size);

//---check_valid_path.c---
int		check_valid_path(t_data *data);

//---file_valid.c---
int		validity(t_data *data, int i, int j);
int		validity2(t_data *data, int i, int j);
int		validity3(t_data *data, int i, int j);
int		validity4(t_data *data, int i, int j);
int		validity5_check(t_data *data);

//---get_f.c---
int		get_f(t_data *data, int i, int j);
int		get_f_malloc(t_data *data, int i, int j, int pos);
void	get_f_copy(t_data *data, int i, int j, int index);
void	get_malloc_init(int *nflag, int *cflag, int *index);
int		validity_flag_set(int *nflag, int *cflag, char cur);

//---get_c.c---
int		get_c(t_data *data, int i, int j);
int		get_c_malloc(t_data *data, int i, int j, int pos);
void	get_c_copy(t_data *data, int i, int j, int index);

//--get_nesw.c--
int		get_no(t_data *data, int i, int j);
int		get_ea(t_data *data, int i, int j);
int		get_so(t_data *data, int i, int j);
int		get_we(t_data *data, int i, int j);

//---get_tex.c---
int		get_tex_malloc(t_data *data, int i, int j, char spc);
char	*get_tex_copy(t_data *data, int i, int j, int index);
void	get_tex_transfer(t_data *data, char *hold, char spc);
int		check_invalid_after(t_data *data, int i, int j);

//---color_convert.c---
int		color_check(t_data *data);
int		color_check2(t_data *data);
void	color_convert(t_data *data, int r, int g, int b);

//---color_convert2.c---
int		convert_r(t_data *data, int i, int mod);
int		convert_g(t_data *data, int i, int mod);
int		convert_b(t_data *data, int i, int mod);
int		go_next_val(t_data *data, int mod);

//---get_map.c---
int		get_map(t_data *data, int i);
int		check_map_items(char c);
int		map_2d_malloc(t_data *data, int pos, int index);
int		map_1d_malloc(t_data *data, int pos, int j, int i);
int		map_1d_copy(t_data *data, int pos, int i);

//---get_map2.c---
void	map_clean(t_data *data);
void	map_recopy(t_data *data, int longest);

//---map_valid.c---
int		map_valid(t_data *data, int i, int j);
int		map_check_perimeter(t_data *data, int i, int j, int mod);
int		map_check_perimeter2(t_data *data, int i, int j, int mod);
int		map_check_void(t_data *data, int i, int j);

//--castray.c---
char	get_wall_orientation(t_map *map, int x, int y, t_ray *ray);
int		is_wall(t_map *map, double x, double y, t_ray *ray);
void	find_h_intersection_n(t_ray *ray, t_map *map, t_player *player);
void	find_h_intersection_s(t_ray *ray, t_map *map, t_player *player);
void	find_v_intersection_w(t_ray *ray, t_map *map, t_player *player);
void	find_v_intersection_e(t_ray *ray, t_map *map, t_player *player);
void	find_h_intersection(t_ray *ray, t_map *map, t_player *player);
void	find_v_intersection(t_ray *ray, t_map *map, t_player *player);
void	cast_single_ray(t_ray *ray, t_map *map, t_player *player);

//---draw.c---
void		draw_rect(t_rect *rect, int *img, int res_width);
void		draw_ceilling(t_game *game);
void		draw_floor(t_game *game);
t_texture	get_wall_texture(t_display *display, char orientation);
double		get_wall_height(t_game *game, t_ray *ray);
int			get_y_wall_position(t_game *game, double wall_height);
int			get_bitmap_offset(t_ray *ray, int bitmap_width);
void		draw_wall_strip(t_rect *rect, int *img, t_display *display, t_ray *ray);
void		draw_walls(t_game *game);
void		draw(t_game *game);

//---update.c---
void	update_player_position(t_player *player, char **grid);
void	update_player_orientation(t_player *player);
void	raycasting(t_game *game);
void	update(t_game *game);
int		render_next_frame(t_game *my_struct);

//---init.c---
void	init_display_params(t_game *game, t_data *data);
void	init_player_params(t_game *game, t_data *data);
void	init_ray_params(t_game *game);
void	init_textures(void *mlx, t_display *display, t_data *data);
void	init_all(t_game *game, t_data *data);

//---keys.c---
int		key_pressed(int keycode, t_data *data);
int		key_released(int keycode, t_game *game);
int		close_window(int keycode, t_data *data);
int 	mouse_move(int x, int y, t_game *game);

//---utils.c---
double	deg_to_rad(double deg);
double	normalize_radian(double radian);
int		get_map_height(char **map);
int 	get_map_width(char **map);
void	get_player_pos(char **map, double *px, double *py);
double	get_player_dir(char c);

//---free_exit.c---
void	free_exit(t_data *data, int code);
void	free2d(char **arr);
void	free_exit_msg(t_data *data, int code, char *msg);

#endif
