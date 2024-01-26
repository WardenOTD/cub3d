/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:22:55 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 18:42:29 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# if __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_F 102
#  define KEY_L_ARROW 65361
#  define KEY_R_ARROW 65363
#  define KEY_SPACE 49
#  define X_WINDOW 17
# else
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_F 3
#  define KEY_L_ARROW 123
#  define KEY_R_ARROW 124
#  define KEY_SPACE 49
#  define X_WINDOW 17
# endif

# if __linux__
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# else
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# endif

# define PI 3.14159265358979323846
# define DR 0.0174533

# define V_RESOLUTION 896
# define H_RESOLUTION 1664
# define SCALE 64
# define FOV_ANGLE 60
# define MOVE_SPEED 0.1
# define ROT_SPEED 4

#endif
