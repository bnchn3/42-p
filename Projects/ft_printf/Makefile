# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 13:34:04 by bchan             #+#    #+#              #
#    Updated: 2018/02/09 17:15:50 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
DIR_S = printf
SOURCE = apply_flag.c apply_width.c form.c ft_printf.c length_h.c length_hh.c \
	   length_j.c length_l.c length_ll.c length_z.c length.c prec_aux.c \
	   precision.c pull.c spec.c
SRCS = $(addprefix $(DIR_S)/,$(SOURCE))
OBJ = $(SOURCE:.c=.o)
INC = printf/libftprintf.h
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS) -I $(INC)

$(LIBFT):
	make -C ./libft/
	cp ./libft/libft.a ./$(NAME)

test: $(NAME)
	$(CC) $(FLAGS) -c main.c -I $(INC)
	$(CC) -o $@ main.o -L. -lftprintf

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm test
	make fclean -C ./libft/

re: fclean all
