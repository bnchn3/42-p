# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 13:04:44 by bchan             #+#    #+#              #
#    Updated: 2018/02/21 13:21:37 by bchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	   ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	   ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	   ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	   ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strcat.c ft_strchr.c \
	   ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	   ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	   ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	   ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	   ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	   ft_toupper.c ft_putstr.c ft_putstr_fd.c ft_btree_apply_infix.c \
	   ft_btree_apply_prefix.c ft_btree_apply_suffix.c \
	   ft_btree_create_node.c ft_btree_insert_data.c ft_btree_search_item.c \
	   ft_strpchar.c ft_strpstr.c ft_hex_convert.c ft_insert_char.c \
	   ft_max_itoa.c ft_meminsert.c ft_octal_convert.c ft_power.c \
	   ft_strnew_char.c ft_strrev.c ft_unsigned_itoa.c ft_dtoa.c ft_swap.c\
		 ft_capitalize.c ft_lstadd_end.c get_next_line.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc -Wall -Wextra -Werror -c $(SRCS) -I.

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
