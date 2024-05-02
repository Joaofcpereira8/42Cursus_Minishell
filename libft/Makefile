# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:16:23 by jofilipe          #+#    #+#              #
#    Updated: 2024/01/25 14:30:50 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
		ft_atol.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_realloc.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islonglong.c \
		ft_isprint.c \
		ft_atoll.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_printf_checkconversion.c \
		ft_printf.c \
		ft_printf_char.c \
		ft_printf_digit.c \
		ft_printf_pointer.c \
		ft_printf_string.c \
		ft_printf_unsigned.c \
		ft_printf_hexa.c \
		ft_printf.c \
		ft_printf_char.c \
		ft_printf_digit.c \
		ft_printf_pointer.c \
		ft_printf_string.c \
		ft_printf_unsigned.c \
		ft_printf_hexa.c \
		get_next_line.c \

OBJ = $(SRC:.c=.o)

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ)

re: fclean all

