# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:24:46 by bchan             #+#    #+#              #
#    Updated: 2017/11/09 16:27:02 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra ft_cat.c -o $(NAME)

clean:
	/bin/rm -f *.o;

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
