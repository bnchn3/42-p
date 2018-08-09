/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:51:14 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 13:57:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function memcmp(). The function will compare the first
** n bytes of the memory areas s1 and s2 and return an integer greater than,
** equal to, or less than zero depending on whether the first n bytes in s1 are
** greater than, equal to, or less than the first n bytes of s2, respectively.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr[i] != ptr2[i])
			return (ptr[i] - ptr2[i]);
		i++;
	}
	return (0);
}
