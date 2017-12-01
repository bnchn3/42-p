/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:50:41 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 12:51:44 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "ft_opp.h"

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

int		ft_usage(char *s1, char *s2)
{
	int		i;

	i = 0;
	ft_putstr(s1);
	while (i < 5)
	{
		{
			ft_putstr(g_opptab[i].opp);
			ft_putchar(' ');
			i++;
		}
	}
	ft_putstr(s2);
	return (0);
}

void	print_doop(t_opp op, char **argv)
{
	if (ft_strcmp("", op.opp))
	{
		op.fp("error: only [ ", "] are accepted.");
	}
	else
	{
		if (op.fp == &ft_div && ft_atoi(operand(argv[3])) == 0)
			ft_putstr("Stop : division by zero");
		else if (op.fp == &ft_mod && ft_atoi(operand(argv[3])) == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(expression(op.fp, operand(argv[1]),
						operand(argv[3])));
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_opp		op;
	int			i;

	i = 0;
	if (argc != 4)
		;
	else
	{
		while (i < 5)
		{
			if (ft_strcmp(argv[2], g_opptab[i].opp))
			{
				op = g_opptab[i];
				break ;
			}
			else
				op = g_opptab[5];
			i++;
		}
		print_doop(op, argv);
	}
	return (1);
}
