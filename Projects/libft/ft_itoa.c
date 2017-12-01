/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:25:19 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 13:01:17 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == -2147483648 || n == 2147483647)
	{
		len += 10;
		return (len);
	}
	if (n == 0)
		return (len + 1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		i;

	result = ft_strnew(ft_intlen(n));
	i = ft_intlen(n) - 1;
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	if (n == 0)
		result = "0";
	while (n != 0)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (result);
}
