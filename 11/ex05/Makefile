SRC_DIR	= src/

OBJ_DIR	= bin/

NAME	= do-op

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

SRCS	= do-op.c ft_atoi.c operator.c utils.c

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all:			$(NAME)


$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR):		
				@mkdir -p $@

clean:
				rm -rf $(OBJ_DIR)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all


.PHONY:			all clean fclean re
