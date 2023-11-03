# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:32:15 by jofilipe          #+#    #+#              #
#    Updated: 2023/11/03 18:57:14 by jofilipe         ###   ########.fr        #
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

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lreadline
RM = rm -rf

LIBFT = libft/libft.a

SRCS =	mandatory/main.c\
		mandatory/exec.c\
		mandatory/readline.c\
		mandatory/get_user.c\
		




OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		clear
		echo "$(BLUE)  __  __ _       _     _          _ _ ";
		echo "$(WHITE) |  \/  (_)     (_)   | |        | | |";
		echo "$(BLUE) | \  / |_ _ __  _ ___| |__   ___| | |";
		echo "$(WHITE) | |\/| | | '_ \| / __| '_ \ / _ \ | |";
		echo "$(BLUE) | |  | | | | | | \__ \ | | |  __/ | |";
		echo "$(WHITE) |_|  |_|_|_| |_|_|___/_| |_|\___|_|_|";
		echo "                                      ";
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
