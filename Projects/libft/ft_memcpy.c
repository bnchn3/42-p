/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:22:39 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 13:59:33 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function memcpy(). The function will copy n bytes of
** the memory pointed to by src to the memory pointed to by dst and return a
** pointer to dst. The memory areas must not overlap, otherwise it is
** considered undefined behavior.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	unsigned char		*ptr2;

	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}
