/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:50:41 by bchan             #+#    #+#             */
/*   Updated: 2017/11/06 15:53:00 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

t_ptr	operator(char *str, t_ptr *array)
{
	array[0] = &ft_add;
	array[1] = &ft_sub;
	array[2] = &ft_mult;
	array[3] = &ft_div;
	array[4] = &ft_mod;
	if (str[0] == '+')
		return (array[0]);
	if (str[0] == '-')
		return (array[1]);
	if (str[0] == '*')
		return (array[2]);
	if (str[0] == '/')
		return (array[3]);
	if (str[0] == '%')
		return (array[4]);
	return (0);
}

char	*operand(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}

int		expression(t_ptr fp, char *s1, char *s2)
{
	return (fp(s1, s2));
}

int		main(int argc, char **argv)
{
	t_ptr		array[5];
	t_ptr		op;

	if (argc != 4)
		;
	else
	{
		if (operator(argv[2], array))
		{
			op = operator(argv[2], array);
			if (op == &ft_div && ft_atoi(operand(argv[3])) == 0)
				ft_putstr("Stop : division by zero");
			else if (op == &ft_mod && ft_atoi(operand(argv[3])) == 0)
				ft_putstr("Stop : modulo by zero");
			else
				ft_putnbr(expression(op, operand(argv[1]),
							operand(argv[3])));
		}
		else
			ft_putchar('0');
		ft_putchar('\n');
	}
	return (1);
}
