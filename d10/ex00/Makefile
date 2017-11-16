# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 11:48:15 by bchan             #+#    #+#              #
#    Updated: 2017/11/07 17:35:44 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILENAMES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
HEADER = ./includes/

SOURCES = $(addprefix srcs/, $(FILENAMES))
OBJECTS = $(addprefix ./, $(FILENAMES:.c=.o))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SOURCES) -I $(HEADER)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
