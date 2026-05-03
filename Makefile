NAME	= libftprintf.a
FLAGS	= -Wall -Wextra -Werror
SRCS =	ft_printf.c ft_hexnmbr.c \
		ft_ptrnmb.c ft_unsignednmber.c \
		ft_decimalnmbr.c
OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY:		all clean fclean re
