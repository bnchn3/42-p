# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 13:27:32 by bchan             #+#    #+#              #
#    Updated: 2018/08/01 13:27:33 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
SRC = main.c input.c commands1.c commands2.c execute.c sort_check.c
OBJ = $(SRC:.c=.o)
INC = checker.h
LIBFT = ../ft_printf/libft/libft.a
LIB = -L ../ft_printf/libft -lft
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) -I $(INC) $(LIB)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INC)

$(LIBFT):
	make -C ../ft_printf/libft/

clean:
	/bin/rm -f $(OBJ)
	make clean -C ../ft_printf/libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ../ft_printf/libft/

re: fclean all
