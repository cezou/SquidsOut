NAME = libft.a

UP = \033[1A
ERASE = \033[0J

all: check_libft

check_libft:
	@if [ ! -f $(NAME) ]; then \
			make --silent making; \
			make --silent $(NAME); \
			make --silent echo; \
			make --silent oclean; \
	fi

$(NAME):
	@make --silent -C gnl
	@make --silent -C printfd
	@make --silent -C minmax
	@cp printfd/libftprintf.a $(NAME)
	@cp gnl/gnl.a .
	@cp minmax/minmax.a .
	@ar x gnl.a
	@ar x minmax.a
	@ar rc $(NAME) *.o
	@rm *.o
	@rm gnl.a
	@rm minmax.a

echo:
	@echo "$(UP)$(UP)$(ERASE)\033[1;32mMade QuoicouLibft :)\033[0m"

making:
	@echo "\033[1;35m🦑🦑🦑 Making QuoicouLibft... 🦑🦑🦑\033[0m"

oclean:
	@make --silent fclean -C ./libft
	@make --silent fclean -C ./gnl
	@make --silent fclean -C ./printfd
	@make --silent fclean -C ./minmax

clean: clean_o clean_a 
	@echo "\033[35m🦑🦑🦑 Crampting QuoicouLibft... 🦑🦑🦑\033[0m"
	@make --silent fclean -C ./libft
	@echo "\033[31m          Redlight FIRST LIBFT!\033[0m"
	@make --silent fclean -C ./gnl
	@echo "$(UP)$(ERASE)\033[31m              Redlight GNL!\033[0m"
	@make --silent fclean -C ./printfd
	@echo "$(UP)$(ERASE)\033[31m            Redlight PRINTFs!\033[0m"
	@make --silent fclean -C ./minmax
	@echo "$(UP)$(ERASE)\033[31m            Redlight MINMAX!\033[0m"

fclean:
	@if [ -f $(NAME) ]; then \
			make --silent fclean_no_check; \
	fi

fclean_no_check: clean
	@rm -f $(NAME) 
	@echo "$(UP)$(UP)$(ERASE)\033[1;31mQuoicouLibft crampted :(\033[0m"

re: fclean all

clean_o:
	@rm -f *.o

clean_a:
	@rm -f gnl.a libftprintf.a minmax.a