#ifndef CONSTANTS_H
# define CONSTANTS_H

# if __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_L_ARROW 65361
#  define KEY_R_ARROW 65363
#  define X_WINDOW 33
# else
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_L_ARROW 123
#  define KEY_R_ARROW 124
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

# define PI 3.141592
# define DR 0.0174533

# define V_RESOLUTION 896
# define H_RESOLUTION 1664
# define SCALE 64
# define FOV_ANGLE 60
# define MOVE_SPEED 0.05
# define ROT_SPEED 3

#endif