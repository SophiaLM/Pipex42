NAME = pipex.a

LIB = ar rcs

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -r

SRC = pipex.c \
      path.c

OBJ = $(SRC:%.c=%.c)

all: $(NAME)

$(NAME): $(OBJ)
	make all -C libft42
	$(LIB) $(NAME) $(OBJ)

%o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft42

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft42

re: fclean all

.PHONY: all clean fclean re
