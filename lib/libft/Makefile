NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I.

PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRCS = \
	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
	ft_strlen.c ft_strncmp.c ft_strcmp.c ft_strrchr.c ft_toupper.c \
	ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_atol.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_split_v2.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
	ft_putunsigned_dec_fd.c ft_putunsigned_hex_fd.c \
	ft_numlen_dec.c ft_numlen_hex.c ft_max.c ft_abs.c ft_count_words.c

BONUS_SRCS = \
	ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: OBJS += $(OBJS_BONUS)
bonus: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	$(MAKE) -s -C $(PRINTF_DIR) --no-print-directory
	@cp $(PRINTF_LIB) .
	@ar -x libftprintf.a && ar rcs $(NAME) *.o
	@rm -f libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS) *.o
	$(MAKE) -s -C $(PRINTF_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	$(MAKE) -s -C $(PRINTF_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re bonus