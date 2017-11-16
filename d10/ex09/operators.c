/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:54:44 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 12:31:17 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_add(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_atoi(s1);
	j = ft_atoi(s2);
	return (i + j);
}

int		ft_sub(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_atoi(s1);
	j = ft_atoi(s2);
	return (i - j);
}

int		ft_mul(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_atoi(s1);
	j = ft_atoi(s2);
	return (i * j);
}

int		ft_div(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_atoi(s1);
	j = ft_atoi(s2);
	return (i / j);
}

int		ft_mod(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_atoi(s1);
	j = ft_atoi(s2);
	return (i % j);
}
