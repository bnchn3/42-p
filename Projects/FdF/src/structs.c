/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:53:56 by bchan             #+#    #+#             */
/*   Updated: 2018/04/09 14:53:57 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	struct_del(t_list **grid, t_list **proj)
{
	t_list	*temp;

	while (*grid)
	{
		temp = (*grid)->next;
		if ((*grid)->content)
			ft_memdel(&((*grid)->content));
		ft_memdel((void **)grid);
		*grid = temp;
	}
	while (*proj)
	{
		temp = (*proj)->next;
		if ((*proj)->content)
			ft_memdel(&((*proj)->content));
		ft_memdel((void **)proj);
		*proj = temp;
	}
}

void	map_del(t_map *map)
{
	int i;
	int	j;

	i = 0;
	if (map)
	{
		if (map->mat)
		{
			while (i < map->y)
			{
				j = 0;
				if (map->mat[i])
				{
					while (map->mat[i][j])
						ft_strdel(&(map->mat[i][j++]));
					ft_memdel((void **)&(map->mat[i]));
				}
				i++;
			}
			ft_memdel((void **)&(map->mat));
		}
		ft_memdel((void **)&map);
	}
}
