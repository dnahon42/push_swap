# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 14:05:47 by dnahon            #+#    #+#              #
#    Updated: 2025/06/12 17:15:10 by dnahon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
CC 			= 	cc
CFLAGS 		= 	-g3 -Wall -Wextra -Werror

LDFLAGS		= 	-Llibft -lft
AR 			= 	ar rcs
RM 			= 	rm -f
SRC_DIR 	= 	./src/push_swap
SRC 		= 	./src/push_swap/push_swap.c ./src/push_swap/push_swap_utils.c \
				./src/push_swap/parse.c ./src/push_swap/instructions.c \
				./src/push_swap/instructions2.c ./src/push_swap/sort.c \
				./src/push_swap/radix.c ./src/push_swap/push_swap_utils2.c\

LIBFT 		= 	./libft/libft.a
INCLUDES	= 	./includes/push_swap.h ./includes/libft.h ./includes/ft_printf.h

OBJ 		= 	$(SRC:.c=.o)

# Color codes
GREEN 		= 	\033[0;32m
YELLOW 		= 	\033[0;33m
RED 		= 	\033[0;31m
BLUE 		= 	\033[0;34m
PURPLE 		= 	\033[0;35m
CYAN 		= 	\033[0;36m
NC 			= 	\033[0m # No Color

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft --no-print-directory
	@echo "$(GREEN)Building $(NC)$(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c $(INCLUDES)
	@echo "$(CYAN)Compiling $(NC)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C libft clean --no-print-directory
	@echo "$(CYAN)Cleaning object files"
	@$(RM) $(OBJ) libft.a

fclean: clean
	@$(MAKE) -C libft fclean --no-print-directory
	@echo "$(CYAN)Cleaning $(NC)$(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
