/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:57:09 by bchan             #+#    #+#             */
/*   Updated: 2018/04/09 15:07:52 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	**z_convert(t_map *map)
{
	t_list	**grid;
	t_vec	*vec;
	int		i;
	int		j;

	grid = (t_list **)malloc(sizeof(t_list *));
	*grid = ft_lstnew(NULL, 0);
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			vec = new_vec(j - (map->x / 2.0), ft_atoi(map->mat[i][j]) / 10.0,
				i - (double)map->y);
			ft_lstadd(grid, ft_lstnew(vec, sizeof(t_vec)));
			j++;
		}
		i++;
	}
	return (grid);
}

void	rotate_grid(t_list *grid, double mid)
{
	t_vec	*vec;

	vec = grid->content;
	vec->z -= mid;
	vec->x = vec->x * cos(M_PI / 4) + vec->z * sin(M_PI / 4);
	vec->z = vec->x * sin(M_PI / 4) * -1 + vec->z * cos(M_PI / 4);
	vec->y = vec->y * cos(M_PI / 4) - vec->z * sin(M_PI / 4);
	vec->z = vec->y * sin(M_PI / 4) + vec->z * cos(M_PI / 4) + mid;
}

t_list	**project(t_list **grid)
{
	t_list	*temp;
	t_vec	*vec;
	t_list	**proj;
	t_coor	*coor;

	proj = (t_list **)malloc(sizeof(t_list *));
	*proj = ft_lstnew(NULL, 0);
	temp = *grid;
	while (temp->next)
	{
		coor = (t_coor *)malloc(sizeof(t_coor));
		vec = temp->content;
		coor->x = vec->x / (vec->z * -1);
		coor->y = vec->y / (vec->z);
		ft_lstadd(proj, ft_lstnew(coor, sizeof(t_coor)));
		temp = temp->next;
	}
	return (proj);
}

void	fov(t_list **proj)
{
	t_list	*temp;
	t_coor	*coor;
	double	max;

	temp = *proj;
	max = 0.0;
	while (temp->next)
	{
		coor = temp->content;
		if (fabs(coor->x) > max)
			max = fabs(coor->x);
		if (fabs(coor->y) > max)
			max = fabs(coor->y);
		temp = temp->next;
	}
	temp = *proj;
	while (temp->next)
	{
		coor = temp->content;
		coor->x *= 1 / max;
		coor->y *= 1 / max;
		temp = temp->next;
	}
}

void	remap(t_list **proj)
{
	t_list	*temp;
	t_coor	*coor;

	temp = *proj;
	while (temp->next)
	{
		coor = temp->content;
		coor->x = (1 + coor->x) / 2 * 700 + 50;
		coor->y = (1 + coor->y) / 2 * 700 + 50;
		temp = temp->next;
	}
}
