CC = cc
ROOT_DIR = $(shell pwd)
LIBFT_DIR = $(ROOT_DIR)/lib/libft
MINILIBX_DIR = $(ROOT_DIR)//lib/minilibx
PRINTF_DIR = $(ROOT_DIR)//lib/printf

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBRARY = -lmlx -lft -lftprintf

INCS = ./inc
SRCS = ./src/*.c ./src/gnl/*.c
LIBS = ./lib

NAME = fdf

${NAME}: all

all:
	make -C ${LIBFT_DIR}
	make -C ${MINILIBX_DIR}
	make -C ${PRINTF_DIR}
	${CC} ${CFLAGS} -I${INCS} -L${LIBFT_DIR} -L${MINILIBX_DIR} -L${PRINTF_DIR} ${LIBRARY} ${FRAMEWORKS} ${SRCS} -o ${NAME}

clean:
	${RM} ${LIBFT_DIR}/*.o
	${RM} ${MINILIBX_DIR}/*.o
	${RM} ${PRINTF_DIR}/*.o

fclean: clean
	${RM} ${LIBFT_DIR}/*.a
	${RM} ${MINILIBX_DIR}/*.a
	${RM} ${PRINTF_DIR}/*.a
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re