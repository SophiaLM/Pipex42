NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf 

LIB = libft42/libft.a \

SRC = pipex.c \
      path.c 

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	make all -C libft42
	gcc $(CFLAGS) $(OBJ) -o $(NAME)


all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean : clean
	$(RM)  $(NAME)
	make fclean -C libft42

clean :
	$(RM) $(NAME)
	make clean -C libft42

re : fclean all

.PHONY: all bonus clean fclean re
