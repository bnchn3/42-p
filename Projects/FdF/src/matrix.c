/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:24:53 by bchan             #+#    #+#             */
/*   Updated: 2018/03/14 14:24:55 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**mat_mult_3(int **a, int **b)
{
	int i;
	int j;
	int	**result;

	i = 0;
	j = 0;
	result = (int **)malloc(sizeof(int *) * 3);
	while (i < 3)
	{
		result[i] = (int *)malloc(sizeof(int) * 3);
		while (j < 3)
		{
			result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
			j++;
		}
		i++;
	}
	return (result);
}

int	**mat_mult_4(int **a, int **b)
{
	int i;
	int j;
	int	**result;

	i = 0;
	j = 0;
	result = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		result[i] = (int *)malloc(sizeof(int) * 4);
		while (j < 4)
		{
			result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j]
			+ a[i][3] * b[3][j];
			j++;
		}
		i++;
	}
	return (result);
}
