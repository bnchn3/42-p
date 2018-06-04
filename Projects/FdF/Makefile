# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 15:10:07 by bchan             #+#    #+#              #
#    Updated: 2018/05/16 17:48:35 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = project.c draw.c reader.c structs.c points.c main.c keycodes.c
LINE = get_next_line.c
SOURCES = $(addprefix src/, $(SRC)) $(addprefix get_next_line/, $(LINE))
OBJ = $(SRC:.c=.o) $(LINE:.c=.o)
INC = src/fdf.h
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a
LIBS = -L libft -lft -L minilibx -lmlx
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Wall -Werror -Wextra
FRAME = -framework OpenGL -framework AppKit

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
	LDFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) -I $(INC) $(LIBS) $(FRAME)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INC)

$(LIBFT):
	make -C ./libft/

$(MLX):
	make -C ./minilibx/

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft/
	make clean -C ./minilibx/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/
	make fclean -C ./minilibx/

re: fclean all
