NAME		= cub3D
CC			= cc
GCC			= gcc-10
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

CRIT_DIR	= lib/criterion-2.4.3
CRIT_INC	= -I $(CRIT_DIR)/include
CRIT_LIBDIR	= $(CRIT_DIR)/lib
CRIT_LIBS	= -L $(CRIT_LIBDIR) -lcriterion

INCLUDE		= -I include -I ${LIBFT_DIR} -I ${MLX_DIR}
LDFLAGS		= -lm -lXext -lX11

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/events/close.c \
			  $(SRC_DIR)/init/framebuffer.c \
			  $(SRC_DIR)/render/render.c \
			  $(SRC_DIR)/player/player_init.c \
			  $(SRC_DIR)/parsing/file.c \
			  $(SRC_DIR)/parsing/utils.c \
			  $(SRC_DIR)/parsing/textures.c \
			  $(SRC_DIR)/parsing/colors.c \
			  $(SRC_DIR)/parsing/colors_utils.c \
			  $(SRC_DIR)/parsing/map_parse.c \
			  $(SRC_DIR)/parsing/map_parse_utils.c \
			  $(SRC_DIR)/parsing/map_closed.c \
			  $(SRC_DIR)/parsing/map_closed_utils.c \
			  $(SRC_DIR)/parsing/player_spawn.c
OBJS		= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

TEST_NAME	= tests_bin
TEST_DIR	= tests
TEST_SRCS	= $(TEST_DIR)/unit/parsing/test_parsing_unit.c \
			  $(TEST_DIR)/integration/parsing/test_parsing_integration.c \
			  $(SRC_DIR)/parsing/file.c \
			  $(SRC_DIR)/parsing/utils.c \
			  $(SRC_DIR)/parsing/textures.c \
			  $(SRC_DIR)/parsing/colors.c \
			  $(SRC_DIR)/parsing/colors_utils.c \
			  $(SRC_DIR)/parsing/map_parse.c \
			  $(SRC_DIR)/parsing/map_parse_utils.c \
			  $(SRC_DIR)/parsing/map_closed.c \
			  $(SRC_DIR)/parsing/map_closed_utils.c \
			  $(SRC_DIR)/parsing/player_spawn.c
TEST_OBJS	= ${TEST_SRCS:%.c=${OBJ_DIR}/%.test.o}

# Coverage flags (tests only)
COV_FLAGS := -fprofile-arcs -ftest-coverage -O0 -g

GCOVR		= ./lib/gcovr-8.6-linux-x86_64
GCOV		= gcov-10

# ======================== BINARY =========================
all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_LIB} ${MLX_LIB}
	mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} ${LDFLAGS} -o ${BIN_DIR}/${NAME}
	cp ${BIN_DIR}/${NAME} ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p ${@D}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

# ======================== TESTS =========================
${OBJ_DIR}/%.test.o: %.c
	mkdir -p ${@D}
	${GCC} ${CFLAGS} ${INCLUDE} $(CRIT_INC) -I ${TEST_DIR} ${COV_FLAGS} -c $< -o $@

${OBJ_DIR}/tests/%.o: tests/%.c
	mkdir -p ${@D}
	${GCC} ${CFLAGS} ${INCLUDE} $(CRIT_INC) -I ${TEST_DIR} ${COV_FLAGS} -c $< -o $@

${TEST_NAME}: ${TEST_OBJS} ${LIBFT_LIB}
	${GCC} ${CFLAGS} -no-pie ${COV_FLAGS} ${TEST_OBJS} ${LIBFT_LIB} $(CRIT_LIBS) -Wl,-rpath,$(CRIT_LIBDIR) -o ${TEST_NAME}

test: ${TEST_NAME}

test-run: test
	./${TEST_NAME} --verbose --color=always

# ======================== COVERAGE =======================
coverage: test-run
	@echo "Generating coverage reports..."
	@$(GCOVR) -r . --gcov-executable $(GCOV) --exclude 'lib/' --exclude 'tests/' --json-summary coverage.json
	@$(GCOVR) -r . --gcov-executable $(GCOV) --exclude 'lib/' --exclude 'tests/' --txt --txt-metric branch
	@echo "✅ Coverage reports generated"

# ======================== LIBS ===========================
$(LIBFT_LIB):
	make -s -C ${LIBFT_DIR} --no-print-directory

$(MLX_LIB):
	make -s -C ${MLX_DIR} --no-print-directory

# ======================== CLEAN ==========================
clean:
	${RM} ${OBJ_DIR}
	${RM} ${TEST_NAME}
	${RM} coverage.json
	make -s -C ${LIBFT_DIR} clean --no-print-directory
	make -s -C ${MLX_DIR} clean --no-print-directory

fclean: clean
	${RM} ${BUILD_DIR}
	${RM} ${NAME}
	make -s -C ${LIBFT_DIR} fclean --no-print-directory
	${RM} ${MLX_LIB}

re: fclean all

.PHONY: all clean fclean re test test-run coverage
