/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:17:28 by ttran             #+#    #+#             */
/*   Updated: 2017/11/12 12:26:35 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2tools.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		strcmp_and_free(char *s1, char *s2)
{
	int result;
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	result = s1[i] - s2[i];
	free(s1);
	return (result);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int		print_success(char n, int x, int y, int use_or)
{
	if (use_or)
		write(1, " || ", 4);
	write(1, "[rush-0", 7);
	ft_putchar(n);
	write(1, "] [", 3);
	ft_putnbr(x);
	write(1, "] [", 3);
	ft_putnbr(y);
	write(1, "]", 1);
	return (1);
}
