/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:25:33 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 13:47:53 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function memccpy(). The function will copy up to n
** bytes of the memory area src to the memory area dst, stopping if the
** character c is found and returning a pointer to the next character after c
** in dst. If c is not found in the first n bytes of src, NULL is returned.
** Overlapping memory areas will result in undefined behavior.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*ptr;
	char		*ptr2;

	i = 0;
	ptr = (char *)dst;
	ptr2 = (char *)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		if (ptr2[i] == (char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
