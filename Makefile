NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS =	src/path.c\
		libft42/libft.a\

$(NAME) :
	make all -C libft42
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft42

clean :
	$(RM) $(NAME)
	make clean -C libft42

re : fclean all

.PHONY: all bonus clean fclean re
