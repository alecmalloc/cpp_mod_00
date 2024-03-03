.SILENT:
NAME	=	accounts
CFLAGS	=	-Wall -Wextra -Werror
CC		=	c++

# ANSI escape codes for colored output
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
NO_COLOR		= \033[0m

SRC	= Account.cpp

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "$(GREEN)$(NAME) ready.$(NO_COLOR)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -std=c++98
	@echo "$(YELLOW)Compiling $(NAME)...$(NO_COLOR)"

clean:
	@echo "$(RED)Cleaning up...$(NO_COLOR)"
	@rm -rf $(OBJ)
	@echo "$(RED)Done cleaning up.$(NO_COLOR)"

fclean: clean
	@echo "$(RED)Cleaning up...$(NO_COLOR)"
	@rm -rf $(NAME)
	@echo "$(RED)Done cleaning up.$(NO_COLOR)"

re: fclean all
	@./$(NAME)

run: $(NAME)
	./$(NAME)

r: $(NAME)
	./$(NAME)