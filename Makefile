NAME		=	so_long

CC			=	clang

FLAG		=	-Wall -Wextra -Werror -g3

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH),libmlx.a)

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c

SRC_DIR		=	./core/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.o: %.c
	$(cc) $(FLAG) -c $< -o $@

all: $(NAME)

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created"

$(NAME): mlx $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	@$(CC) $(OBJ) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@echo "\033[1;32mDone"

re: fclean all

.PHONY: all clean fclean re
