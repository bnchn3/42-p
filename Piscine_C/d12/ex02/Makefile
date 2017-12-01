# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:14:32 by bchan             #+#    #+#              #
#    Updated: 2017/11/09 18:32:14 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror ft_tail.c -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
