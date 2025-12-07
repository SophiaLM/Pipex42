NAME = pipex

LIB = ar rcs

CFLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

LIBFT = ./libft42/libft.a \

PASTEL_PINK = \033[38;5;218m

STRONG_PINK = \033[38;5;204m

LILAC = \033[38;5;141m

RESET = \033[0m

SRC = pipex.c \
      path.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME) kitty

$(NAME): $(OBJ)
	@make all -C libft42 > /dev/null 2>&1
	@echo "$(PASTEL_PINK)compiling $(STRONG_PINK)libft..."
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@echo "$(PASTEL_PINK)compiling $(STRONG_PINK)$<..."
	@$(CC) $(CFLAGS) -c $< -o $@

kitty:
	@echo "$(STRONG_PINK)  /\_/\                       /\_/\ $(RESET)"
	@echo "$(STRONG_PINK) ( ovo ) $(PASTEL_PINK)¡So_long is ready!  $(STRONG_PINK)( owo )$(RESET)"
	@echo "$(STRONG_PINK)   >🐟 <                     > 🐟 < $(RESET)"

clean: clean_kitty
	@$(RM) $(OBJ)
	@make clean -C libft42 > /dev/null 2>&1

clean_kitty:
	@echo "$(STRONG_PINK)  /\_/\                          /\_/\ $(RESET)"
	@echo "$(STRONG_PINK) ( -.- ) $(PASTEL_PINK)¡All objects removed!  $(STRONG_PINK)( -w- )$(RESET)"
	@echo "$(STRONG_PINK)   >🗑️ <                        > 🗑️ < $(RESET)"

fclean: fclean_kitty
	@make clean  > /dev/null 2>&1
	@$(RM) $(NAME)
	@make fclean -C libft42 > /dev/null 2>&1

fclean_kitty:
	@echo "$(STRONG_PINK)  /\_/\                             /\_/\ $(RESET)"
	@echo "$(STRONG_PINK) ( >n< ) $(PASTEL_PINK)¡Full cleanup completed!  $(STRONG_PINK)( >w< )$(RESET)"
	@echo "$(STRONG_PINK)  > 💀 <                           > 💀 < $(RESET)"

re: fclean all

.PHONY: all clean fclean re
