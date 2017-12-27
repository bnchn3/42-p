/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:00:47 by bchan             #+#    #+#             */
/*   Updated: 2017/12/05 11:58:56 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(size + (size_t)1);
	i = (size_t)0;
	if (result)
	{
		while (i < size + (size_t)1)
		{
			result[i] = '\0';
			i++;
		}
		return (result);
	}
	return (NULL);
}
