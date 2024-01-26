UNAME := $(shell uname -s)

# norminette draw/ gnl/ libft/ minimap/ parsing/ raycasting/ utils/ constants.h cub3d.h free_exit.c init.c keys.c main.c main2.c structs.h

SRC			= main.c main2.c\
				parsing/file_extension.c\
				parsing/check_valid_path.c\
				parsing/get_file.c\
				parsing/file_valid.c\
				parsing/get_f.c parsing/get_c.c parsing/get_nesw.c parsing/get_tex.c\
				parsing/color_convert.c parsing/color_convert2.c\
				parsing/get_map.c parsing/get_map2.c parsing/map_valid.c\
				raycasting/castray.c raycasting/castray2.c raycasting/update.c\
				draw/draw.c draw/draw2.c\
				utils/utils.c utils/utils2.c\
				minimap/minimap.c\
				init.c keys.c free_exit.c\

GNL			= gnl/get_next_line.c\
				gnl/get_next_line_utils.c\

# MacOs
ifeq ($(UNAME), Darwin)
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
FSANITIZE	= -fsanitize=address -g
DSYM		= && rm -rf *.dSYM

MLX			= libmlx.a
LIBFT		= libft.a
NAME		= cub3d

all:	${NAME}

${NAME}: ${MLX} ${LIBFT} ${SRC} ${GNL}
	${CC} ${CFLAGS} ${MLXFLAGS} ${FSANITIZE} ${SRC} ${GNL} ${LIBFT} ${MLX} -o ${NAME} ${DSYM}

${LIBFT}:
	make -s all -C libft/
	mv libft/libft.a .

${MLX}:
	make -s all -C mlx_mac/
	mv mlx_mac/libmlx.a .

clean:
	@${RM} *.o
	make -s clean -C libft/
	make -s clean -C mlx_mac/

fclean: clean
	${RM} $(NAME) ${LIBFT} ${MLX}
	make -s fclean -C libft/

re:	fclean all

.PHONY: all
endif

# Linux (Wsl)
ifeq ($(UNAME), Linux)
SRCS_LIBFT	= libft/*.c
OBJ			= $(SRC:.c=.o)
OBJ_GNL		= $(GNL:.c=.o)
OBJ_LIBFT	= $(SRCS_LIBFT:.c=.o)

NAME 		= cub3d
CC			= gcc
RM			= rm -f
FSANITIZE	= -fsanitize=address -g
CFLAGS 		= -Wall -Wextra -Werror
DSYM		= && rm -rf *.dSYM
MLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(NAME): $(OBJ) $(OBJ_GNL) ${LIBFT}
	@$(CC) $(OBJ) $(OBJ_GNL) $(OBJ_LIBFT) $(MLXFLAGS) $(FSANITIZE) -o $(NAME) $(DSYM)

%.o: %.c
	@gcc $(CFLAG) -c $< -o $(<:.c=.o)

${LIBFT}:
	make -s all -C libft/
	mv libft/libft.a .

clean :
	@${RM} $(OBJ) $(OBJ_GNL)
	make -s clean -C libft/

fclean : clean
	@${RM} $(NAME) ${LIBFT}
	make -s fclean -C libft/

re : fclean all

.PHONY: all
endif
