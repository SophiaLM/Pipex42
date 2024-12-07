NAME = pipex

LIB = ar rcs

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

FTLIB = Libft42/libft.a

SRC = pipex.c 

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C Libft42
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@$(MAKE) clean -C Libft42
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C Libft42
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
