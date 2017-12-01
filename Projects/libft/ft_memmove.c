/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:30:35 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 13:51:28 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp;
	size_t		i;
	char		*ptr;
	char		*ptr2;

	temp = (char *)malloc(len);
	ptr = (char *)dst;
	ptr2 = (char *)src;
	i = 0;
	while (i < len)
	{
		temp[i] = ptr2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		ptr[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
