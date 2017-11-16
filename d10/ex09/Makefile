# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 13:48:49 by bchan             #+#    #+#              #
#    Updated: 2017/11/07 15:04:34 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op
FILENAMES = do_op.c strings.c operators.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(FILENAMES) -o $(NAME) -I do_op.h -I ft_opp.h

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
