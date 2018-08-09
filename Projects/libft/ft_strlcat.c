/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:46:11 by bchan             #+#    #+#             */
/*   Updated: 2017/12/07 12:34:05 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function strlcat(). The function will append at most
** size - strlen(dst) - 1 bytes of the string src onto the end of dst, null
** terminating the result. The function will return the total length of the
** string it tried to create (initial length of dst plus the length of src).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	while (dst[i] && i < size)
	{
		len++;
		i++;
	}
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (len);
}
