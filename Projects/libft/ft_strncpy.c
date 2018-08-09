/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:12:58 by bchan             #+#    #+#             */
/*   Updated: 2017/11/27 15:06:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function strncpy(). The function will copy the first
** len bytes of the string src to dst, returning a pointer to dst. If len is
** less than the length of src, the copied string is not null terminated. If
** len is greater than the length of src, null terminators are added onto the
** end of the copied string until len bytes are written.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len > 0)
	{
		dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}
