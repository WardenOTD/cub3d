/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:57:42 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/12 17:31:57 by jteoh            ###   ########.fr       */
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
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# if __linux__
#  include <X11/X.h>
#  include "mlx_linux/mlx.h"
# else
#  include <mlx.h>
# endif

typedef struct s_mlx
{
	void	*mlx_ptr; //mlx pointer
	void	*win_ptr; //window pointer
	void	*wall_ptr[4]; //4 wall texture pointer
	void	*spr_ptr; //sprite texture pointer
}				t_mlx;

typedef struct s_data
{
	//bunch of variables for mlx, add more if needed
	t_mlx	mlx; //mlx variable struct
	char	**file; //double array to store the contents of the *.cub file
	char	**map; //double array to store the map
	char	*n_path; //texture path North wall
	char	*e_path; //texture path East wall
	char	*s_path; //texture path South wall
	char	*w_path; //texture path West wall
	char	*c_color; //ceiling color
	char	*f_color; //floor color
	int		parse_check;
	char	ply_dir; //player spawning direction
	int		pcount; //count of player symbols (N, E, S, W) for validation
}				t_data;

//---get_map.c---
int		parse(t_data *data, char *argv);
int		check_line_empty(char *line);
void	realloc2d(t_data *data, int size);
int		validity(t_data *data);

//---get_f.c---
int		get_f(t_data *data, int i, int j);
int		get_f_malloc(t_data *data, int i, int j);
void	get_f_copy(t_data *data, int i, int j, int index);
void	get_malloc_init(int *nflag, int *cflag, int *index);
int		validity_flag_set(int *nflag, int *cflag, char cur);

//---get_c.c---
int		get_c(t_data *data, int i, int j);
int		get_c_malloc(t_data *data, int i, int j);
void	get_c_copy(t_data *data, int i, int j, int index);

//--get_nesw.c--
int	get_no(t_data *data, int i, int j);
int	get_ea(t_data *data, int i, int j);
int	get_so(t_data *data, int i, int j);
int	get_we(t_data *data, int i, int j);

//---get_tex.c---
int		get_tex_malloc(t_data *data, int i, int j, char spc);
char	*get_tex_copy(t_data *data, int i, int j, int index);
void	get_tex_transfer(t_data *data, char *hold, char spc);
int		check_invalid_after(t_data *data, int i, int j);

#endif
