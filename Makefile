SRC			= test.c\
				get_map.c\

GNL			= gnl/get_next_line.c\
				gnl/get_next_line_utils.c\

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
FSANITIZE	= -fsanitize=address -g
DSYM		= && rm -rf *.dSYM

LIBFT		= libft.a
NAME		= cub3d

all:	${NAME}

${NAME}: ${LIBFT} ${SRC}
	${CC} ${CFLAGS} ${MLXFLAGS} ${FSANITIZE} ${SRC} ${GNL} ${LIBFT} -o ${NAME} ${DSYM}

${LIBFT}:
	make -s all -C libft/
	mv libft/libft.a .

clean:
	@${RM} *.o
	make -s clean -C libft/

fclean: clean
	${RM} $(NAME) ${LIBFT}
	make -s fclean -C libft/

re:	fclean all

.PHONY: all
