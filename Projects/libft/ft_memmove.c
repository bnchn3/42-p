/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:30:35 by bchan             #+#    #+#             */
/*   Updated: 2017/12/07 12:22:38 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	char		*sour;

	if (!((int *)dst > (int *)src && (int *)src + len > (int *)dst))
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		dest = (char *)dst;
		sour = (char *)src;
		while (i > 0)
		{
			i--;
			dest[i] = sour[i];
		}
	}
	return (dst);
}
