/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:57:42 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/11 13:23:45 by jteoh            ###   ########.fr       */
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
	char	**map; //double array to store the map
	char	*path_n; //texture path North wall
	char	*path_e; //texture path East wall
	char	*path_s; //texture path South wall
	char	*path_w; //texture path West wall
	char	ply_dir; //player spawning direction
	int		pcount; //count of player symbols (N, E, S, W) for validation
}				t_data;

#endif
