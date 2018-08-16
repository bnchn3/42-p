/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:51:06 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 13:15:45 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a "fresh" memory area of size bytes.
** The memory allocated is initialized to 0. If the allocation fails, the
** function returns NULL.  
*/

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = (void *)malloc(size);
	if (result)
	{
		ft_bzero(result, size);
		return (result);
	}
	return (NULL);
}
