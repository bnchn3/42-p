# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 14:23:51 by ttran             #+#    #+#              #
#    Updated: 2017/11/11 20:09:21 by ttran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-2

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) -I includes srcs/*.c

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
