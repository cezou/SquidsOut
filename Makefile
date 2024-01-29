# SQUIDS OUT
NAME = so_long

# COMPILATION
CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -I/usr/include -Imlx_linux -O3 -lXext -lX11 -lm

# DIRECTORIES
S_DIR = srcs
M_DIR = maps
T_DIR = textures
O_DIR = objs
I_DIR = includes
L_DIR = $(I_DIR)/QuoicouLibft
MLX_DIR = $(I_DIR)/minilibx-linux

# FILES
SRCS = $(S_DIR)/*.c
LIBFT = $(L_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
INCS = $(LIBFT) $(MLX)
HEAD = $(I_DIR)/so_long.h

# TEXT
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
PURPLE = \033[38;5;105m
PINK = \033[38;5;206m

BOLD = \033[1m
UNDERLINE = \033[4m
RESET = \033[0m

UP = \033[1A
ERASE = \033[0J

all : MLX QuoicouLibft $(NAME)

MLX:
	@make --silent -C $(MLX_DIR)

QuoicouLibft:
	@make --silent -C $(L_DIR)

$(NAME): $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) $(INCS) -I${HEAD} -o $(NAME)
	@echo "$(GREEN)  ● Made SoLong$(RESET)"

clean:
	@rm -f $(NAME)

fclean:
	@make --silent fclean -C $(L_DIR)
	@if [ -f $(NAME) ]; then \
			make --silent fclean_no_check; \
	fi

fclean_no_check: clean
	@echo "$(PINK)    Adios Squidos 🦑$(RESET)"

re : fclean all

.PHONY: QuoicouLibft clean fclean re all
