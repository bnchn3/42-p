/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:31:02 by bchan             #+#    #+#             */
/*   Updated: 2017/12/07 10:59:21 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	size_t			j;

	result = (char *)malloc(len + 1);
	if (s && result)
	{
		i = start;
		j = 0;
		while (j < len)
		{
			result[j] = s[i];
			i++;
			j++;
		}
		result[j] = '\0';
		return (result);
	}
	return (NULL);
}
