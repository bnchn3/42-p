/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:56:09 by bchan             #+#    #+#             */
/*   Updated: 2018/04/09 15:06:02 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vert(t_coor *start, t_coor *end, t_map *map)
{
	int y;

	y = start->y;
	while (y != (int)end->y)
	{
		mlx_pixel_put(map->mlx, map->win, start->x, y, map->color);
		if (y > end->y)
			y--;
		else if (y < end->y)
			y++;
	}
}

void	bresenham(t_coor *start, t_coor *end, int x, t_map *map)
{
	double	error;
	int		y;

	if (end->x - start->x != 0)
	{
		error = 0.0;
		y = start->y;
		while (x != (int)end->x)
		{
			mlx_pixel_put(map->mlx, map->win, x, y, map->color);
			error += fabs((end->y - start->y) / (end->x - start->x));
			while (error >= 0.5)
			{
				y += copysign(1.0, end->y - start->y);
				error -= 1.0;
			}
			if (x > end->x)
				x--;
			else if (x < end->x)
				x++;
		}
	}
	else
		draw_vert(start, end, map);
}

void	draw_up(t_list *temp, t_map *map, int i, int j)
{
	t_coor	*start;
	t_coor	*end;
	int		n;

	if (i > 0)
	{
		start = temp->content;
		n = j;
		while (j-- >= 0)
			temp = temp->next;
		i--;
		j = 0;
		while (map->mat[i][j + 1] != NULL)
			j++;
		while (j-- > n)
			temp = temp->next;
		end = temp->content;
		bresenham(start, end, start->x, map);
	}
}

void	draw_left(t_list *temp, t_map *map, int j)
{
	t_coor	*start;
	t_coor	*end;

	if (j > 0)
	{
		start = temp->content;
		temp = temp->next;
		end = temp->content;
		bresenham(start, end, start->x, map);
	}
}

void	draw(t_list **proj, t_map *map)
{
	t_list	*temp;
	t_coor	*coor;
	int		i;
	int		j;

	temp = *proj;
	i = map->y - 1;
	while (i >= 0)
	{
		j = 0;
		while (map->mat[i][j + 1] != NULL)
			j++;
		while (j >= 0)
		{
			coor = temp->content;
			mlx_pixel_put(map->mlx, map->win, coor->x, coor->y, map->color);
			draw_up(temp, map, i, j);
			draw_left(temp, map, j);
			temp = temp->next;
			j--;
		}
		i--;
	}
}
