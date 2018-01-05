/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:11:31 by bchan             #+#    #+#             */
/*   Updated: 2017/12/07 11:34:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	if (s && f)
	{
		i = 0;
		result = (char *)malloc(ft_strlen(s) + 1);
		if (result)
		{
			while (s[i])
			{
				result[i] = f(s[i]);
				i++;
			}
			result[i] = '\0';
			return (result);
		}
	}
	return (NULL);
}
