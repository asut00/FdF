# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 15:44:04 by asuteau           #+#    #+#              #
#    Updated: 2024/05/31 15:44:14 by asuteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------- VARIABLES --------------------------------- #

NAME = fdf

SOURCES = 	src/main.c \
			src/check/checks_01.c \
			src/check/checks_02.c \
			src/check/checks_03.c \
			src/check/checks_04.c \
			src/init/init_map_vars.c \
			src/init/init_scale_and_mlx_vars.c \
			src/utils/point_tab.c \
			src/draw/draw.c \
			src/draw/draw_pixels.c \
			src/draw/draw_lines_01.c \
			src/draw/draw_lines_02.c \
			src/draw/draw_columns_01.c \
			src/draw/draw_columns_02.c \
			src/utils/atois_and_events.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I inc -I /usr/local/include -I ./libft -I ./minilibx
LDFLAGS = -L /usr/local/lib -L libmlx_Linux -L libft -L ./minilibx
LIBS = -lft -lmlx -lX11 -lXext -lm

# ---------------------------------- RULES ----------------------------------- #

.c.o:	
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) -C libft

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJECTS)
	@$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
