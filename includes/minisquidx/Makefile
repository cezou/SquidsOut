# MINISQUIDX
NAME = minisquidx.a

# COMPILATION
CC = cc 
CFLAGS = -g
MLXFLAGS = -I/usr/include -Imlx_linux -O3 -lXext -lX11 -lm

# DIRECTORIES
D_SRC = srcs
D_DRAW = $(D_SRC)/draw
D_UTILS = $(D_SRC)/utils
D_MLX = minilibx-linux
L_DIR = quoicoulibft

# FILES
MLX = $(D_MLX)/libmlx.a
SRCS = $(D_SRC)/*.c $(D_DRAW)/*.c $(D_UTILS)/*.c
OBJS = $(SRCS:.c=.o)
LIBFT = $(L_DIR)/libft.a

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

all : $(LIBFT) $(NAME)

$(LIBFT):
	@if [ ! -d $(L_DIR) ]; then \
		echo "$(MAGENTA)Cloning QuoicouLibft...$(RESET)" ; \
		git clone git@github.com:cezou/QuoicouLibft.git $(L_DIR) > /dev/null 2>&1; \
		echo "$(UP)$(ERASE)$(BOLD)$(GREEN)QuoicouLibft Cloned$(RESET)" ; \
	fi
	@make --silent -C $(L_DIR)

$(MLX):
	@if [ ! -d $(D_MLX) ]; then \
	echo "$(MAGENTA)Cloning minilibx...$(RESET)"; \
	git clone https://github.com/42Paris/minilibx-linux.git $(D_MLX) > /dev/null 2>&1; \
	echo "$(UP)$(ERASE)$(BOLD)$(GREEN)Minilibx Cloned$(RESET)"; \
	fi
	@make --silent -C $(D_MLX) > /dev/null 2>&1;

$(NAME): $(MLX)
	@cp $(MLX) $(NAME) ; \
	cp $(LIBFT) . ; \
	ar x $(LIBFT) ; \
	ar rcs $(NAME) *.o > /dev/null 2>&1; \
	rm -f *.o libft.a; \
	echo "$(PINK)Squiding...$(RESET)" ; \
	for file in $(SRCS); do \
		$(CC) $(CFLAGS) -c $$file -o $${file%.c}.o -I. ; \
	done ; \
	ar rcs $(NAME) $(OBJS) > /dev/null 2>&1; \
	make --silent clean ; \
	echo "$(UP)$(ERASE)$(BOLD)$(PINK)  ● MiniLibX got BOOSTED by MiniSquidX 🦑$(RESET)"

clean:
	@rm -f $(OBJS)

fclean: clean
	@make --silent -C $(L_DIR) fclean;
	@if [ -d $(D_MLX) ] ; then \
		echo "$(PINK)Crampting MiniSquidX...$(RESET)" ; \
		make --silent -C $(D_MLX) clean > /dev/null 2>&1; \
		echo "$(UP)$(ERASE)$(BOLD)$(PINK)● MiniSquidX Crampted!$(RESET)" ; \
	fi
	@rm -f $(NAME);

rmf :
	@rm -f $(NAME)
	@rm -rf $(L_DIR)
	@rm -rf $(D_MLX)

re : fclean all

.PHONY: clean fclean re all rmf
