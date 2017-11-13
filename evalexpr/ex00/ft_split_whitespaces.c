/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:42:56 by bchan             #+#    #+#             */
/*   Updated: 2017/11/11 11:42:42 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"
#include <stdlib.h>

int		ft_wordlength(char *str, int i)
{
	int		len;

	len = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

int		ft_wordcount(char *str)
{
	int		i;
	int		wordcount;
	int		sym;

	i = 0;
	wordcount = 0;
	while (str[i])
	{
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
		{
			i++;
			sym = 1;
		}
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			if (sym == 1)
			{
				wordcount++;
				sym = 0;
			}
			i++;
		}
	}
	return (wordcount);
}

char	**ft_split_whitespaces(char *str)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	if ((result = malloc(sizeof(char *) * (ft_wordcount(str) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((result[j] = malloc(ft_wordlength(str, i) + 1)) == NULL)
				return (NULL);
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
				result[j][k++] = str[i++];
			result[j++][k] = '\0';
		}
	}
	result[j] = NULL;
	return (result);
}
