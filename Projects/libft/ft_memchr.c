/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:46:31 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 13:58:53 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function memchr(). The function will scan the first n
** bytes of the memory area s for the character c, returning a pointer to the
** first matching byte or NULL if the character is not found.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*result;
	unsigned char	*ptr;

	i = 0;
	result = NULL;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			result = (void *)&ptr[i];
			break ;
		}
		i++;
	}
	return (result);
}
