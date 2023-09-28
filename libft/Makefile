################################################################################
#                                     CONFIG                                   #
################################################################################

NAME_PROJECT = Libft
NAME         = libft.a
CC           = cc
FLAGS        = -Wall -Wextra -Werror -g #-fsanitize=address


################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################
SRCS			= 		  ft_atoi.c \
	  					  ft_bzero.c \
						  ft_isalnum.c \
						  ft_isalpha.c \
						  ft_isascii.c \
						  ft_isdigit.c \
						  ft_isprint.c \
						  ft_memchr.c \
						  ft_memcmp.c \
						  ft_memcpy.c \
						  ft_memmove.c \
						  ft_memset.c \
						  ft_strlcat.c \
						  ft_strlcpy.c \
						  ft_strchr.c \
						  ft_strrchr.c \
						  ft_strncmp.c \
						  ft_strdup.c \
						  ft_strlen.c \
						  ft_strnstr.c \
						  ft_tolower.c \
						  ft_toupper.c \
						  ft_calloc.c \
						  ft_substr.c \
						  ft_strjoin.c \
						  ft_strtrim.c \
						  ft_split.c \
						  ft_itoa.c \
						  ft_strmapi.c \
						  ft_striteri.c \
						  ft_putchar_fd.c \
						  ft_putstr_fd.c \
						  ft_putendl_fd.c \
	 					  ft_putnbr_fd.c \
						  ft_lstnew.c \
						  ft_lstadd_front.c \
						  ft_lstsize.c \
						  ft_lstlast.c \
						  ft_lstadd_back.c \
						  ft_lstdelone.c \
						  ft_lstclear.c \
						  ft_lstiter.c \
						  ft_lstmap.c \
						  get_next_line.c \
						  get_next_line_utils.c \
						  ft_printf.c \
						  ft_putchar.c \
						  ft_putnbr.c \
						  ft_put_nbr_lower.c \
						  ft_put_nbr_upper.c \
						  ft_put_point_hexa.c \
						  ft_putstr.c \
						  ft_put_unsig_dec.c \
						  						 	  
OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))


################################################################################
#                                     COLORS                                   #
################################################################################


CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
RESET		= \033[0m
RM		    = rm -rf

################################################################################
#                                                                              #
################################################################################

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
#			clear
#			@echo "$(BLUE)Compilation of $(NAME_PROJECT): $(GREEN)[OK]$(RESET)"
#			@echo "$(BLUE)$(NAME_PROJECT) created:        $(GREEN)[OK]$(RESET)"

$(OBJ_DIR)/%.o: %.c
	    	@mkdir -p $(dir $@)
	        @$(CC) $(CFLAGS) -c $< -o $@

clean:
			@${RM} $(OBJS) $(OBJ_DIR)
			@ echo "$(RED)Deleting $(NAME_PROJECT) objs   ${GREEN}[OK]$(RESET)"

fclean:		clean
			@${RM} ${NAME}
			@ echo "$(RED)Deleting $(NAME_PROJECT) binary ${GREEN}[OK]$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
