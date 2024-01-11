/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:57:42 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/11 11:21:21 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_data
{
	//bunch of variables for mlx add more if needed
	char	**map;
	void	*mlx;
	void	*win;
	void	*wall[4];
	void	*sprite;
	char	ply_dir;
	int		pcount;
}				t_data;

#endif
