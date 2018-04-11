/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:27:28 by bchan             #+#    #+#             */
/*   Updated: 2018/04/11 11:27:31 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		escape_key(int key, t_map *map)
{
	if (key == 53)
	{
		map_del(map);
		exit(EXIT_SUCCESS);
	}
	if (key == 69 || key == 78 || (key >= 123 && key <= 126))
		move_key(key, map);
	if (key == 8)
		color_key(key, map);
	return (0);
}

int		move_key(int key, t_map *map)
{
	if (key == 126)
		map->up++;
	if (key == 123)
		map->left++;
	if (key == 125)
		map->up--;
	if (key == 124)
		map->left--;
	if (key == 69)
		map->zoom++;
	if (key == 78)
		map->zoom--;
	if (key == 69 || key == 78 || (key >= 123 && key <= 126))
	{
		mlx_clear_window(map->mlx, map->win);
		find_vertices(map->mlx, map->win, map);
	}
	return (0);
}

int		color_key(int key, t_map *map)
{
	if (key == 8)
	{
		if (map->color == 0x00FFFFFF)
			map->color = 0x00FF0000;
		else if (map->color == 0x00FF0000)
			map->color = 0x00FF8B00;
		else if (map->color == 0x00FF8B00)
			map->color = 0x00F0FF00;
		else if (map->color == 0x00F0FF00)
			map->color = 0x0000FF0C;
		else if (map->color == 0x0000FF0C)
			map->color = 0x000042FF;
		else if (map->color == 0x000042FF)
			map->color = 0x008F00FF;
		else
			map->color = 0x00FFFFFF;
		mlx_clear_window(map->mlx, map->win);
		find_vertices(map->mlx, map->win, map);
	}
	return (0);
}
