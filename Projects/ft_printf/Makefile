# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 13:34:04 by bchan             #+#    #+#              #
#    Updated: 2018/02/09 13:44:49 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = printf/apply_flag.c printf/apply_width.c printf/form.c \
	   printf/ft_printf.c printf/length_h.c printf/length_hh.c \
	   printf/length_j.c printf/length_l.c printf/length_ll.c \
	   printf/length_z.c printf/length.c printf/prec_aux.c printf/precision.c \
	   printf/pull.c printf/spec.c
OBJ = $(SRCS:.c=.o)
INC = printf/libftprintf.h
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS) -I $(INC)

$(LIBFT):
	make -C ./libft/

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/

all: fclean all
