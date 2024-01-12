UNAME := $(shell uname -s)

SRC			= test.c\
				get_map.c\
				get_f.c get_c.c get_nesw.c get_tex.c\

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

LIBFT		= libft.a
NAME		= cub3d

all:	${NAME}

${NAME}: ${LIBFT} ${SRC} ${GNL}
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
