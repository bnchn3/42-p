/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:58:57 by bchan             #+#    #+#             */
/*   Updated: 2018/02/23 18:23:08 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_spec(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
		c == 's' || c == 'p' || c == 'c' || c == 'D' || c == 'U' || c == 'O' ||
		c == 'S' || c == 'C' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||
		c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'n' || c == '%')
		return (1);
	return (0);
}

char	get_spec(const char *format)
{
	int	i;

	i = 0;
	while (!(check_spec(format[i])))
		i++;
	return (format[i]);
}

int		number_spec(char c)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'n')
		return (0);
	return (1);
}

int		number_spec2(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'f' || c == 'F' || c == 'e' ||
		c == 'E')
		return (1);
	return (0);
}
