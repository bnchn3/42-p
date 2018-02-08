/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:37:33 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 15:47:31 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long long n)
{
	size_t	len;

	len = 0;
	if (n == -9223372036854775808)
	{
		len += 20;
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

char			*ft_max_itoa(long long n)
{
	char	*result;
	int		i;

	result = (char *)ft_strnew(ft_intlen(n));
	if (result)
	{
		i = ft_intlen(n) - 1;
		if (n == -9223372036854775808)
			result = ft_strcpy(result, "-9223372036854775808");
		else if (n < 0)
		{
			result[0] = '-';
			n *= -1;
		}
		else if (n == 0)
			result[0] = '0';
		while (n != 0 && n != -9223372036854775808)
		{
			result[i--] = n % 10 + '0';
			n /= 10;
		}
	}
	return (result);
}
