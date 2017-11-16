/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:11:15 by bchan             #+#    #+#             */
/*   Updated: 2017/11/02 12:33:58 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*arr;
	int		i;
	int		j;

	if (min >= max)
	{
		arr = (int *)0;
		return (arr);
	}
	i = 0;
	j = min;
	arr = (int *)malloc(sizeof(*arr) * (max - min));
	while (i < (max - min))
	{
		arr[i] = j;
		i++;
		j++;
	}
	return (arr);
}
