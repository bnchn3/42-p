/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:17:01 by bchan             #+#    #+#             */
/*   Updated: 2017/12/07 14:55:40 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlength(char const *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static int		ft_wordcount(char const *s, char c)
{
	int		i;
	int		wordcount;
	int		sym;

	i = -1;
	wordcount = 0;
	if (!s)
		return (-2);
	while (s[++i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			sym = 1;
		}
		if (s[i] == c || s[i] == '\0')
		{
			if (sym == 1)
			{
				wordcount++;
				sym = 0;
			}
		}
	}
	return (wordcount);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	if (!(result = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(result[j] = (char *)malloc(ft_wordlength(s, c, i) + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				result[j][k++] = s[i++];
			result[j++][k] = '\0';
		}
	}
	result[j] = NULL;
	return (result);
}
