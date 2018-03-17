/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:44:06 by bchan             #+#    #+#             */
/*   Updated: 2018/03/14 11:44:07 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec	*new_vec(double x, double y, double z)
{
	t_vec *vec;

	vec = (t_vec *)malloc(sizeof(t_vec));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec	*translate(t_vec *point, double x, double y, double z)
{
	t_vec	*new;

	new = new_vec(point->x, point->y, point->z);
	new->x += x;
	new->y += y;
	new->z += z;
	return (new);
}

t_vec	*scale(t_vec *point, double scale)
{
	t_vec	*new;

	new = new_vec(point->x, point->y, point->z);
	new->x *= scale;
	new->y *= scale;
	new->z *= scale;
	return (new);
}
