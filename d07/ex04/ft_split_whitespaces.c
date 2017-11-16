/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:42:56 by bchan             #+#    #+#             */
/*   Updated: 2017/11/02 12:48:46 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_write(char *str, char **result, int len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < len)
	{
		k = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			result[j][k] == str[i];
			i++;
			k++;
		}
		result[j][k] == '\0';
		j++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	result[j] = "0";
	return (result);
}

char	**ft_split_whitespaces(char *str)
{
	char	**result;
	int		i;
	int		len;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
		len++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			len++;
	}
	result = (char **)malloc(sizeof(char) * (len + 2));
	result = ft_write(str, result, len);
	return (result)
}
