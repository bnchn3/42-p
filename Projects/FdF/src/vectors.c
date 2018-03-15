/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:49:34 by bchan             #+#    #+#             */
/*   Updated: 2018/03/14 11:49:37 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	vector_len(t_vec *vec)
{
	double result;

	result = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	return (result);
}

t_vec		*normalize(t_vec *vec)
{
	t_vec		*unit;
	double	inv;
	double	len;

	len = vector_len(vec);
	if (len > 0)
	{
		inv = 1 / len;
		unit = new_vec(vec->x * inv, vec->y * inv, vec->z * inv);
		return (unit);
	}
	return (NULL);
}

double	dot(t_vec *a, t_vec *b)
{
	double result;

	result = a->x * b->x + a->y * b->y + a->z * b->z;
	return (result);
}

t_vec		*cross(t_vec *a, t_vec *b)
{
	t_vec *new;

	new = new_vec(a->y * b->z - a->z * b->y, a->z * b->x - a->x * b->z,
		a->x * b->y - a->y * b->x);
	return (new);
}
