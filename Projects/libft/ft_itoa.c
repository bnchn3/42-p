/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:25:19 by bchan             #+#    #+#             */
/*   Updated: 2017/12/09 12:57:08 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		len += 11;
		return (len);
	}
	if (n < 0)
		len++;
	if (n == 0)
		return (len + 1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_intmin(char *result)
{
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		i;

	result = (char *)ft_strnew(ft_intlen(n));
	if (result)
	{
		i = ft_intlen(n) - 1;
		if (n == -2147483648)
			result = ft_intmin(result);
		else if (n < 0)
		{
			result[0] = '-';
			n *= -1;
		}
		else if (n == 0)
			result[0] = '0';
		while (n != 0 && n != -2147483648)
		{
			result[i--] = n % 10 + '0';
			n /= 10;
		}
	}
	return (result);
}
