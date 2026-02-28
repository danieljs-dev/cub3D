NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

SRC_DIR		= src
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/obj
BIN_DIR		= $(BUILD_DIR)/bin

LIBFT_DIR	= lib/libft
LIBFT_LIB	= ${LIBFT_DIR}/libft.a
MLX_DIR		= lib/minilibx-linux/
MLX_LIB		= ${MLX_DIR}libmlx_Linux.a

INCLUDE		= -I include -I ${LIBFT_DIR} -I ${MLX_DIR}
LDFLAGS		= -lm -lXext -lX11

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/events/close.c \
			  $(SRC_DIR)/init/framebuffer.c \
			  $(SRC_DIR)/render/render.c \
			  $(SRC_DIR)/parsing/file.c \
			  $(SRC_DIR)/parsing/utils.c \
			  $(SRC_DIR)/parsing/textures.c
OBJS		= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_LIB} ${MLX_LIB}
	mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} ${LDFLAGS} -o ${BIN_DIR}/${NAME}
	cp ${BIN_DIR}/${NAME} ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p ${@D}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(LIBFT_LIB):
	make -s -C ${LIBFT_DIR} --no-print-directory

$(MLX_LIB):
	make -s -C ${MLX_DIR} --no-print-directory

clean:
	${RM} ${OBJ_DIR}
	make -s -C ${LIBFT_DIR} clean --no-print-directory
	make -s -C ${MLX_DIR} clean --no-print-directory

fclean: clean
	${RM} ${BUILD_DIR}
	${RM} ${NAME}
	make -s -C ${LIBFT_DIR} fclean --no-print-directory
	${RM} ${MLX_LIB}

re: fclean all

.PHONY: all clean fclean re
