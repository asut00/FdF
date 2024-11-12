# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:29:10 by asuteau           #+#    #+#              #
#    Updated: 2024/05/30 13:53:20 by asuteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------- VARIABLES --------------------------------- #

SRC_DIR	= srcs

SRCS = 	./ft_abs.c \
./ft_strnstr.c \
./ft_isdigit.c \
./ft_putstr_fd.c \
./ft_strlcpy.c \
./ft_strlen.c \
./ft_memcmp.c \
./ft_putnbr_fd.c \
./ft_strchr.c \
./ft_striteri.c \
./ft_bzero.c \
./ft_strjoin.c \
./ft_isascii.c \
./ft_memcpy.c \
./ft_isprint.c \
./ft_putendl_fd.c \
./ft_toupper.c \
./ft_split.c \
./ft_strrchr.c \
./ft_isalpha.c \
./ft_memchr.c \
./ft_putchar_fd.c \
./ft_memset.c \
./ft_substr.c \
./ft_strncmp.c \
./ft_strmapi.c \
./ft_strtrim.c \
./ft_memmove.c \
./ft_strlcat.c \
./ft_calloc.c \
./ft_strdup.c \
./ft_atoi.c \
./ft_isalnum.c \
./ft_itoa.c \
./ft_tolower.c \
./ft_isspace.c \
./ft_iswhitespace.c \
./ft_strlen_until_char.c \
./ft_strcpy.c \
./ft_strlines.c \

OS = $(SRCS:.c=.o)

HD = .

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

# ---------------------------------- RULES ----------------------------------- #

.c.o:
	$(CC) $(CFLAGS) -I $(HD) -c $< -o $(<:.c=.o)

$(NAME) : $(OS)
	ar rcs $(NAME) $(OS)

all: $(NAME)

clean:
	rm -f $(OS)

fclean: clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
