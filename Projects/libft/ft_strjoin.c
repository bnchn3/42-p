/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:39:16 by bchan             #+#    #+#             */
/*   Updated: 2017/12/07 14:19:51 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (s1 && s2)
	{
		result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		i = 0;
		j = 0;
		if (result)
		{
			while (i < ft_strlen(s1))
			{
				result[i] = s1[i];
				i++;
			}
			while (j < ft_strlen(s2))
			{
				result[i++] = s2[j++];
			}
			result[i] = '\0';
		}
		return (result);
	}
	return (NULL);
}
