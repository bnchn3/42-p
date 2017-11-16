/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:28:56 by bchan             #+#    #+#             */
/*   Updated: 2017/11/02 12:34:42 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_arraylength(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*result;
	int		i;
	int		j;
	int		k;
	int		len;

	len = ft_arraylength(argc, argv);
	result = (char *)malloc(sizeof(*result) * len);
	i = 0;
	j = 0;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			result[j] = argv[i][k];
			k++;
			j++;
		}
		result[j] = '\n';
		j++;
		i++;
	}
	return (result);
}
