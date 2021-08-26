SRC_DIR = src/

DEP_DIR = ./includes/

OBJ_DIR	= bin/

SRCS	= ft_cat.c ft_display_file.c ft_main.c ft_utils.c

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

NAME	= ft_cat

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I$(DEP_DIR)

all:			$(NAME)

$(OBJ_DIR):
				@mkdir -p $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -rf $(OBJ_DIR)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
