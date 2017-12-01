/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:31:02 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 12:59:42 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	int				j;

	result = (char *)malloc(len + 1);
	if (result)
	{
		i = start;
		j = 0;
		while (j < (int)len)
		{
			result[j] = s[i];
			i++;
			j++;
		}
		return (result);
	}
	return (NULL);
}
