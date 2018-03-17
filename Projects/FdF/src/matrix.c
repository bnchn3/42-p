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

double	**mat_mult_3(double **a, double **b)
{
	int			i;
	int			j;
	double	**result;

	i = 0;
	j = 0;
	result = (double **)malloc(sizeof(double *) * 3);
	while (i < 3)
	{
		result[i] = (double *)malloc(sizeof(double) * 3);
		while (j < 3)
		{
			result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
			j++;
		}
		i++;
	}
	return (result);
}

double	**mat_mult_4(double **a, double **b)
{
	int 		i;
	int 		j;
	double	**result;

	i = 0;
	j = 0;
	result = (double **)malloc(sizeof(double *) * 4);
	while (i < 4)
	{
		result[i] = (double *)malloc(sizeof(double) * 4);
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

t_vec	*mult_vec_matrix(t_vec *v, double **m)
{
	t_vec		*new;
	double	w;

	new = new_vec(0, 0, 0);
	new->x = v->x * m[0][0] + v->y * m[1][0] + v->z * m[2][0] + m[3][0];
	new->y = v->x * m[0][1] + v->y * m[1][1] + v->z * m[2][1] + m[3][1];
	new->z = v->x * m[0][2] + v->y * m[1][2] + v->z * m[2][2] + m[3][2];
	w = v->x * m[0][3] + v->y * m[1][3] + v->z * m[2][3] + m[3][3];
	if (w != 1 && w != 0)
	{
		new->x /= w;
		new->y /= w;
		new->z /= w;
	}
	return (new);
}

t_vec	*mult_dir_matrix(t_vec *v, double **m)
{
	t_vec		*new;

	new = new_vec(0, 0, 0);
	new->x = v->x * m[0][0] + v->y * m[1][0] + v->z * m[2][0];
	new->y = v->x * m[0][1] + v->y * m[1][1] + v->z * m[2][1];
	new->z = v->x * m[0][2] + v->y * m[1][2] + v->z * m[2][2];
}

double	**transpose_mat(double **m)
{
	int			i;
	int			j;
	double	**n;

	i = 0;
	j = 0;
	n = (double **)mallco(sizeof(double *) * 4);
	while (i < 4)
	{
		n[i] = (double *)malloc(sizeof(double) * 4);
		while(j < 4)
		{
			n[i][j] = m[j][i];
			j++;
		}
		i++;
	}
	return (n);
}
