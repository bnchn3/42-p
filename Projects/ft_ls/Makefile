# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 17:06:53 by bchan             #+#    #+#              #
#    Updated: 2018/05/16 18:08:33 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = delete.c dir_aux.c dir.c files.c long1.c long2.c long3.c main.c pads.c \
	  parse.c sort.c xattr.c
SOURCES = $(addprefix src/, $(SRC))
OBJ = $(SRC:.c=.o)
INC = src/ft_ls.h
LIBFT = libft/libft.a
LIB = -L libft -lft
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Wall -Werror -Wextra

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
	LDFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) -I $(INC) $(LIB)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INC)

$(LIBFT):
	make -C ./libft/

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all
