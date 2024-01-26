/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:27:45 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 17:08:37 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ray
{
	double		x;
	double		y;
	double		size;
	char		obstacle;
	double		angle;
	char		orientation;
	char		side;
	double		x_step;
	double		y_step;
}				t_ray;

typedef struct s_rays
{
	t_ray		*arr; //array of single rays
	double		view_angle; //angle of player's field of vision
	double		dist_proj_plane;
}				t_rays;

typedef struct s_img
{
	void		*img_ptr; //pointer for image
	int			*data; //address for image given by mlx_get_data_addr
	int			bpp; //given by mlx_get_data_addr
	int			size_l; //given by mlx_get_data_addr
	int			endian; //given by mlx_get_data_addr
}	t_img;

typedef struct s_player
{
	double		x; //current x position
	double		y; //current y position
	char		walk_direction; //current direction player is moving
	int			turn_direction; //current direction player is facing
	double		rotation_angle; //initial direction player is facing
	double		move_speed; //grid moved per frame
	double		rotation_speed; //angle moved per frame
}				t_player;

typedef struct s_map
{
	char		**map; //square map represented by a char *
	int			width; //x magnitude of map
	int			height; // y magnitude of map
}				t_map;

typedef struct s_texture
{
	char		*path; //path to image
	void		*img_ptr; //void * for mlx
	int			*data; //address for image given by mlx_get_data_addr
	int			bpp; //given by mlx_get_data_addr
	int			size_l; //given by mlx_get_data_addr
	int			endian; //given by mlx_get_data_addr
	int			width; //image width
	int			height; //image height
}				t_texture;

typedef struct s_display
{
	long long	width; //screen width
	long long	height; //screen height
	t_texture	no_tex; //data structure for north wall texture
	t_texture	so_tex; //data structure for south wall texture
	t_texture	we_tex; //data structure for west wall texture
	t_texture	ea_tex; //data structure for east wall texture
	t_texture	pov;
	int			floor; //floor colour
	int			ceilling; //ceiling colour
	t_map		map; //data structure for map
}				t_display;

typedef struct s_game
{
	void		*mlx; //pointer for mlx
	void		*win; //pointer for win
	//---
	int			activate_mouse;
	int			change_sprite;
	t_player	player; //data structure for player info
	t_rays		rays; //data structure for rays used for raycasting
	t_display	display; //data structure for items involved in the ui
	t_img		frame; //data structure for the frame printed on screen
}				t_game;

typedef struct s_data
{
	//bunch of variables for mlx, add more if needed
	//---
	char	**file; //double array to store the contents of the *.cub file
	int		parse_check; //variable used to verify .cub file elements
	//---
	char	**map; //double array to store the map
	//---
	char	*n_path; //texture path North wall
	char	*e_path; //texture path East wall
	char	*s_path; //texture path South wall
	char	*w_path; //texture path West wall
	//---
	char	*c_color; //ceiling color
	char	*f_color; //floor color
	int		int_c_color; //convert to integer
	int		int_f_color; //convert to integer
	//---
	char	ply_dir; //player spawning direction
	//---
	int		size; //size per block of minimap
	//---
	t_game	game; //game data
}				t_data;

typedef struct s_rect
{
	int			x;
	int			y;
	double		width;
	double		height;
	int			fill_color;
	int			border_color;
	int			border_width;
	t_texture	tex;
}				t_rect;

#endif
