NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I../ -I.

LIBFT_DIR = ../
LIBFT = $(LIBFT_DIR)libft.a

SRCS = \
	ft_printf.c specifiers.c str_wrappers.c \
	num_wrappers.c hex_wrappers.c ptr_wrappers.c \
	errors.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
