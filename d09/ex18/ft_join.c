/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:51:25 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 15:25:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_arraylength(char **tab)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

int		ft_seplength(char *sep)
{
	int		i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int		ft_wordlength(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ft_join(char **tab, char *sep)
{
	char	*result;
	int		i;
	int		j;
	int		k;
	int		len;

	len = ft_arraylength(tab);
	result = (char *)malloc(len + (ft_seplength(sep) * ft_wordlength(tab)));
	i = 0;
	j = 0;
	while (tab[i])
	{
		k = 0;
		while (tab[i][k] != '\0')
			result[j++] = tab[i][k++];
		k = 0;
		while (sep[k])
			result[j++] = sep[k++];
		j++;
		i++;
	}
	result[j - 1] = '\0';
	return (result);
}
