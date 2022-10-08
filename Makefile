CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = ft_printf.c\
			ft_len_sys.c\
			ft_num_sys.c\
			ft_print_sys.c\
			ft_str_sys.c\

MAN_OBJS = $(MANDATORY:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(MAN_OBJS)
	ar r $(NAME) $(MAN_OBJS)
# static library

clean:
	rm -f $(MAN_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re