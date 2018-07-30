/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:41:54 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 15:42:00 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(uintmax_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	while (n != 0)
	{
		n /= (unsigned int)10;
		len++;
	}
	return (len);
}

char			*ft_unsigned_itoa(uintmax_t n)
{
	char	*result;
	int		i;

	result = (char *)ft_strnew(ft_intlen(n));
	if (result)
	{
		i = ft_intlen(n) - 1;
		if (n == 0)
			result[0] = '0';
		while (n != 0)
		{
			result[i--] = n % 10 + '0';
			n /= 10;
		}
	}
	return (result);
}
