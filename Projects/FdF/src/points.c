/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:44:06 by bchan             #+#    #+#             */
/*   Updated: 2018/04/09 15:09:41 by bchan            ###   ########.fr       */
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

void	find_vertices(void *mlx, void *win, t_map *map)
{
	t_list	**grid;
	t_list	*temp;
	t_list	**proj;

	map->mlx = mlx;
	map->win = win;
	grid = z_convert(map);
	temp = *grid;
	while (temp->next)
	{
		rotate_grid(temp, (map->y + 1) / 2.0 * -1);
		temp = temp->next;
	}
	proj = project(grid);
	fov(proj);
	remap(proj);
	draw(proj, map);
	struct_del(grid, proj);
}
