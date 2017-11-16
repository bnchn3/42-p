# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 10:50:00 by bchan             #+#    #+#              #
#    Updated: 2017/11/14 11:35:56 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) -I bsq.h *.c

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
