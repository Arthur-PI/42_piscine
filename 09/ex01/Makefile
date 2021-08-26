DEP_DIR	= ./includes/

SRC_DIR	= ./srcs/

SRC		= ft_swap.c ft_strlen.c ft_putchar.c ft_putstr.c ft_strcmp.c

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I$(DEP_DIR)

.c.o:
			$(CC) $(CFLAGS) -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
