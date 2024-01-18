#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct s_mlx
// {
// 	void	*mlx_ptr; //mlx pointer
// 	void	*win_ptr; //window pointer
// 	void	*wall_ptr[4]; //4 wall texture pointer
// 	void	*spr_ptr; //sprite texture pointer
// }				t_mlx;

typedef struct s_data
{
	//bunch of variables for mlx, add more if needed
	// t_mlx	mlx; //mlx variable struct
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
}				t_data;

typedef struct	s_ray
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

typedef struct	s_rays
{
	t_ray		*arr;
	double		view_angle;
	double		dist_proj_plane;
}				t_rays;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}	t_img;

typedef struct	s_player
{
	double		x; //current x position
	double		y; //current y position
	char		walk_direction; //current direction player is moving
	int			turn_direction; //current direction player is facing
	double		rotation_angle; //initial direction player is facing
	double		move_speed; //grid moved per frame
	double		rotation_speed; //angle moved per frame
}				t_player;

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct	s_texture
{
	char		*path; //path to image
	void		*img_ptr; //void * for mlx
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			width; //image width
	int			height; //image height
}				t_texture;

typedef struct	s_display
{
	long long	width; //screen width
	long long	height; //screen height
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_texture	ea_tex;
	int			floor; //floor colour
	int			ceilling; //ceiling colour
	t_map		map;
}				t_display;

typedef struct s_game
{
	void *mlx;
	void *win;

	t_player	player;
	t_rays		rays;
	t_display	display;
	t_img		frame;
}	t_game;

typedef struct	s_rect
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