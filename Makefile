# SQUIDS OUT
NAME = so_long

# COMPILATION
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -I/usr/include -Imlx_linux -O3 -lXext -lX11 -lm

# DIRECTORIES
S_DIR = srcs
E_DIR = $(S_DIR)/2d_engine
D_DIR = $(E_DIR)/draw
U_DIR = $(E_DIR)/utils
MH_DIR = $(S_DIR)/map_handling
M_DIR = maps
T_DIR = textures
O_DIR = objs
I_DIR = includes
L_DIR = $(I_DIR)/QuoicouLibft
MLX_DIR = $(I_DIR)/minilibx-linux

# FILES
SRCS = $(S_DIR)/*.c $(MH_DIR)/*.c $(U_DIR)/*.c $(E_DIR)/*.c $(D_DIR)/*.c
LIBFT = $(L_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
INCS = $(LIBFT) $(MLX)
HEAD = ./$(I_DIR)/squids_out.h

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

all : $(MLX) $(LIBFT) $(NAME)

v: $(MLX) $(LIBFT) $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

launch:
	@./$(NAME) $1

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)  > /dev/null 2>&1; \
	fi
	@make --silent -C $(MLX_DIR);

$(LIBFT):
	@make --silent -C $(L_DIR)

$(NAME): $(SRCS) $(LIBFT) $(HEAD)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -I${I_DIR} $(SRCS) $(INCS) -o $(NAME)
	@echo "$(GREEN)  ● Made SoLong$(RESET)"

clean:
	@if [ -f $(NAME) ]; then \
			rm -f $(NAME); \
			echo "$(BOLD)$(PINK)  ● Adios Squidos 🦑$(RESET)"; \
	fi

fullclean: fclean
	@rm -rf $(MLX_DIR)

fclean:
	@make --silent fclean -C $(L_DIR)
	@make --silent clean
	@make --silent clean -C $(MLX_DIR)

re : fclean all

.PHONY: QuoicouLibft clean fclean re all
