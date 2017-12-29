# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 12:52:35 by bchan             #+#    #+#              #
#    Updated: 2017/12/28 17:51:51 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = check_file.c four_by_four.c main.c max_dimen.c permutation.c print_square.c read_file.c
OBJ = $(SRCS:.c=.o)
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS)

$(LIBFT):
	make -C ./libft/

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all
