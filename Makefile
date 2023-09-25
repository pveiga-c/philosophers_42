NAME_PROJECT 	   = Philosophers

NAME			   = philo

SRCS			   = $(wildcard src/*.c)

OBJS			   = $(SRCS:.c=.o)

CC 				   = cc 

CFLAGS 			   = -Wall -Wextra -Werror -g # -fsanitize=address

LIBFT_PATH 		   = libft

LIBFT_LIB	       = $(LIBFT_PATH)/libft.a

RM 				   = rm -f

.c.o:
			@$(CC) -c $< -o $@

all:		$(LIBFT_LIB) $(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME) 
#			clear
			@echo "$(BLUE)Compilation $(NAME_PROJECT) $(GREEN)  [OK]$(RESET)"
			@echo "$(BLUE)Successfully built $(GREEN)   [OK]$(RESET)"
	
clean:		
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	clear
	@echo "$(GREEN) $(NAME_PROJECT) $(RED)Objects Removed! $(RESET)"

fclean: 	clean
	$(RM) $(NAME)
	clear
	@echo "$(CYAN) [$(NAME_PROJECT)] $(RED)Objects Removed! $(RESET)"
	@echo "$(CYAN) [$(NAME_PROJECT)] $(RED)"Removed!" $(RESET)"

re: 		fclean all
			
.PHONY: all clean fclean re

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
RESET		= \033[0m