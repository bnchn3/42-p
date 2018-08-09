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

/*
** Identical to the libc function memmove(). The function will copy len bytes
** from memory area src to memory area dst and return a pointer to dst. The
** memory areas can overlap; copying is done in a non-destructive manner.
*/

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
