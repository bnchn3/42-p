/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:46:42 by bchan             #+#    #+#             */
/*   Updated: 2017/12/07 11:47:11 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimlen(char const *s)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		i++;
		len++;
	}
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && len > 0)
	{
		i--;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	int		i;
	size_t	j;

	if (s)
	{
		result = (char *)malloc(ft_trimlen(s) + 1);
		i = 0;
		j = 0;
		if (result)
		{
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
			while (j < ft_trimlen(s))
			{
				result[j] = s[i];
				i++;
				j++;
			}
			result[j] = '\0';
		}
		return (result);
	}
	return (NULL);
}
