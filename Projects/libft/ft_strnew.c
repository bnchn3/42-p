/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:00:47 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 12:59:57 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(size + 1);
	i = 0;
	if (result)
	{
		while (i < size + 1)
		{
			result[i] = '\0';
			i++;
		}
		return (result);
	}
	return (NULL);
}
