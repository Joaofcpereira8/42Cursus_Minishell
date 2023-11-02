# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:32:15 by jofilipe          #+#    #+#              #
#    Updated: 2023/11/02 17:42:28 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm -rf

LIBFT = libft/libft.a

SRCS =


OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		clear
		echo "$(BLUE) _      _  _      _  ____  _     _____ _     _    ";
		echo "$(WHITE)/ \__/|/ \/ \  /|/ \/ ___\/ \ /|/  __// \   / \   ";
		echo "$(BLUE)| |\/||| || |\ ||| ||    \| |_|||  \  | |   | |   ";
		echo "$(WHITE)| |  ||| || | \||| |\___ || | |||  /_ | |_/\| |_/\";
		echo "$(BLUE)\_/  \|\_/\_/  \|\_/\____/\_/ \|\____\\____/\____/";
		echo "$(WHITE)                                                  ";
		echo ""
		echo "$(GREEN)Minishell is ready to go!$(RESET)"


clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) clean -C ./libft
	@$(RM) $(NAME)
	echo "$(RED)Objects and executable files have been erased!$(RESET)"

re: fclean all

.SILENT:
