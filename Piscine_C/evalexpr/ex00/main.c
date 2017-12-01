/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:56:09 by bchan             #+#    #+#             */
/*   Updated: 2017/11/12 16:14:05 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "evalexpr.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(long long nbr)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

int				ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i]);
		i++;
	return (i);
}

long long 	    ft_atoi(char *str)
{
	int			i;
	long long	nbr;
	int			isnegative;

	nbr = 0;
	isnegative = 0;
	i = 0;
	if (str[i] == '-')
		isnegative = 1;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (long long)str[i] - '0';
		i++;
	}
	if (isnegative == 1)
		return (-nbr);
	else
		return (nbr);
}

t_list			create_list_elem(char *str)
{
	t_list	*list;

	list = (t_list)malloc(sizeof(t_list));
	if (list)
	{
		list->next = NULL;
		list->data = str;
	}
	return (list);
}

void			ft_list_push_front(t_list **begin_list, char *data)
{
	t_list		*new_begin;

	new_begin = ft_create_elem(data);
	new_begin->next = *begin_list;
	*begin_list = new_begin;
}

t_list			*create_list(char **result)
{
	t_list		**begin_list;
	int			i;

	i = 0;
	*begin_list = NULL;
	while (result[i])
		i++;
	i--;
	while (i >= 0)
	{
		ft_list_push_front(begin_list, result[i]);
		i--;
	}
	return (begin_list);
}

char			*solve_paren(t_list **begin_list)
{
	t_list		*list;
	char		*str;
	t_list		*new_begin;
	int			n;

	list = *begin_list;
	while (list)
	{
		str = list->data;
		if (str[0] == '(')
		{
			new_begin = list;
			n = 1;
			while (str[ft_strlen(str) - 1] != ')')
			{
				if (str[n] = 
}

void			operate(t_list **begin_list, t_list *end_list)
{
	t_list		*list;
	char		*str;

	list = *begin_list;
	while (list->next != end_list)
	{
		str = list->next->data;
		if (str[0] == '*')
			list = list_mult(list);
		else if (str[0] == '/')
			list = list_div(list);
		else if (str[0] == '%')
			list = list_mod(list);
		else
			list = list->next;
	}
	list = *begin_list;
	while (list->next != end_list)
	{
		str = list->next->data;
		if (str[0] == '+')
			list = list_add(list);
		else if (str[0] == '-')
			list = list_sub(list);
		else
			list = list->next;
	}
}

long long		eval_expr(char *str)
{
	int			i;
	t_list		**begin_list;

	begin_list = create_list(ft_split_whitespaces(str));

}


int				main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
