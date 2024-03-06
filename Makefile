# SQUIDS OUT
NAME = so_long
BONUS = squids_out

# COMPILATION
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -I/usr/include -Imlx_linux -O3 -lXext -lX11 -lm

# DIRECTORIES
I_DIR = includes
MLX_DIR = $(I_DIR)/minisquidx
L_DIR = $(MLX_DIR)/quoicoulibft

D_SRC = $(MLX_DIR)/srcs
D_DRAW = $(D_SRC)/draw
D_UTILS = $(D_SRC)/utils
S_DIR = srcs
MH_DIR = $(S_DIR)/map_handling
M_DIR = maps
T_DIR = textures
O_DIR = objs
E_DIR = $(S_DIR)/events


# FILES
SQUID_SRCS = $(D_SRC)/*.c $(D_DRAW)/*.c $(D_UTILS)/*.c
SRCS = $(S_DIR)/*.c $(MH_DIR)/*.c $(E_DIR)/*.c
MANDATORY_SRCS = $(S_DIR)/mandatory_only/*.c
BONUS_SRCS = $(S_DIR)/squids_out_only/*.c
LIBFT = $(L_DIR)/libft.a
MLX = $(MLX_DIR)/minisquidx.a
INCS = $(LIBFT) $(MLX)

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

all : $(MLX) $(NAME)

v: $(MLX) $(LIBFT) $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

launch:
	@./$(NAME) $1

$(MLX): $(SQUID_SRCS)
	@make --silent -C $(MLX_DIR)

$(LIBFT):
	@make --silent -C $(L_DIR) 

$(NAME): $(SRCS) $(MLX)
	@make --silent -C $(MLX_DIR); \
	$(CC) $(CFLAGS) $(MLXFLAGS) -I${I_DIR} $(SRCS) $(MANDATORY_SRCS) ${INCS} -o $(NAME) ; \
	echo "$(GREEN)    ● Made SoLong$(RESET)"

$(BONUS): $(SRCS) $(MLX)
	@make --silent -C $(MLX_DIR); \
	$(CC) $(CFLAGS) $(MLXFLAGS) -I${I_DIR} $(SRCS) $(BONUS_SRCS) ${INCS} -o $(BONUS) ; \
	echo "$(GREEN)    ● Made SquidsOut$(RESET)"

bonus: $(BONUS)

clean:
	@if [ -f $(NAME) ]; then \
			rm -f $(NAME); \
			echo "$(BOLD)$(PINK)● Adios Squidos 🦑$(RESET)"; \
	fi
	@if [ -f $(BONUS) ]; then \
			rm -f $(BONUS); \
	fi

rmf: clean
	@make --silent -C $(MLX_DIR) rmf

fclean: clean
	@make --silent -C $(MLX_DIR) fclean

re : fclean all

.PHONY: QuoicouLibft clean fclean re all
