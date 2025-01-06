NAME = pipex

LIB = ar rcs

CFLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

LIBFT = ./libft42/libft.a \

SRC = pipex.c \
      path.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	make all -C libft42
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	$(RM) $(OBJ)
	make clean -C libft42

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft42

re: fclean all

.PHONY: all clean fclean re
