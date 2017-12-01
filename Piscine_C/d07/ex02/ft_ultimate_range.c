/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:21:43 by bchan             #+#    #+#             */
/*   Updated: 2017/11/02 12:34:28 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*arr;
	int		i;
	int		j;

	if (min >= max)
	{
		*range = (int *)0;
		return (0);
	}
	else
	{
		i = 0;
		j = min;
		arr = (int *)malloc(sizeof(*arr) * (max - min));
		while (i < (max - min))
		{
			arr[i] = j;
			i++;
			j++;
		}
		range = &arr;
		return (i);
	}
}
