/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:57:40 by bchan             #+#    #+#             */
/*   Updated: 2018/03/12 12:58:40 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*int_convert(char **temp, t_map *map)
{
	int	i;
	int	*result;

	i = 0;
	while (temp[i])
		i++;
	result = (int *)malloc(sizeof(int) * i);
	if (i > map->x)
		map->x = i;
	i = 0;
	while (temp[i])
	{
		result[i] = ft_atoi(temp[i]);
		ft_strdel(&temp[i]);
		i++;
	}
	ft_memdel((void **)&temp);
	return (result);
}

char		**get_x(char **temp, t_map *map)
{
	int	i;

	i = 0;
	while (temp[i])
		i++;
	if (i > map->x)
		map->x = i;
	return (temp);
}

t_map	*matrix_alloc(int fd)
{
	char	buf[1];
	int		ret;
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	while ((ret = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			i++;
	}
	map->mat = (char ***)malloc(sizeof(char **) * i);
	map->y = i;
	map->x = 0;
	map->interval = 50;
	close(fd);
	return (map);
}

t_map	*get_matrix(int argc, char **argv)
{
	int 	i;
	int		fd;
	char	*line;
	char	**temp;
	t_map	*map;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map = matrix_alloc(fd);
	fd = open(argv[1], O_RDONLY);
	while (argc)
	{
		argc = get_next_line(fd, &line);
		temp = ft_strsplit(line, ' ');
		if (argc)
			map->mat[i++] = get_x(temp, map);
	}
	if (map->x > map->y && map->x > 5)
		map->interval = 55 - map->x;
	else if (map->y > map->x && map->y > 5)
		map->interval = 55 - map->y;
	ft_strdel(&line);
	return (map);
}

t_list	**z_convert(t_map *map)
{
	t_list	**grid;
	t_vec		*vec;
	int			i;
	int			j;

	grid = (t_list **)malloc(sizeof(t_list *));
	*grid = ft_lstnew(NULL, 0);
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			vec = new_vec(j, ft_atoi(map->mat[i][j]), -1 * map->y + i);
			ft_lstadd(grid, ft_lstnew(vec, sizeof(t_vec)));
			j++;
		}
		i++;
	}
	return (grid);
}

void	rotate_grid(t_list *grid, double mid)
{
	double	angle;
	double	hyp;
	t_vec		*vec;

	vec = grid->content;
	//angle = atan2(vec->y, vec->z - mid);
	vec->y = vec->y * cos(M_PI / 4) - (vec->z - mid) * sin(M_PI / 4);
	vec->z = vec->y * sin(M_PI / 4) + (vec->z - mid) * cos(M_PI / 4) + mid;
	/*if (angle && angle != M_PI)
	    hyp = vec->y / sin(angle);
	else
	    hyp = fabs(vec->z - mid);
	if (vec->z < mid)
	{
		vec->y = hyp * sin(angle + M_PI / 3);
		vec->z = hyp * cos(angle + M_PI / 3) + mid;
	}
	else if (vec->z > mid)
	{
		vec->y = hyp * sin(angle + M_PI / 3);
		vec->z = hyp * cos(angle + M_PI / 3) + mid;
	}*/
}

t_list	**project(t_list **grid)
{
	t_list	*temp;
	t_vec		*vec;
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

void	remap(t_list **proj)
{
	t_list	*temp;
	t_coor	*coor;
	double	x;
	double	y;

	temp = *proj;
	x = 0.0;
	y = 0.0;
	while (temp->next)
	{
		coor = temp->content;
		if (coor->x > x)
			x = coor->x;
		if (coor->y > y)
			y = coor->y;
		temp = temp->next;
	}
	temp = *proj;
	while (temp->next)
	{
		coor = temp->content;
		coor->x = coor->x / x * 700 + 50;
		coor->y = coor->y / y * 500 + 50;
		temp = temp->next;
	}
}

void 	draw_vert(t_coor *start, t_coor *end, t_map *map)
{
	int y;

	y = start->y;
	while (y != (int)end->y)
	{
		mlx_pixel_put(map->mlx, map->win, start->x, y, 0x00FFFFFF);
		if (y > end->y)
			y--;
		else if (y < end->y)
			y++;
	}
}

void 	bresenham(t_coor *start, t_coor *end, int x, t_map *map)
{
	double	error;
	int			y;

	if (end->x - start->x != 0)
	{
		error = 0.0;
		y = start->y;
		while (x != (int)end->x)
		{
			mlx_pixel_put(map->mlx, map->win, x, y, 0x00FFFFFF);
			error += fabs((end->y - start->y) / (end->x - start->x));
			while (error >= 0.5)
			{
				y += copysign(1.0, end->y - start->y);
				error -= 1.0;;
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
	int			n;

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
	int			i;
	int			j;

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
			mlx_pixel_put(map->mlx, map->win, coor->x, coor->y, 0x00FFFFFF);
			draw_up(temp, map, i, j);
			draw_left(temp, map, j);
			temp = temp->next;
			j--;
		}
		i--;
	}
}

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
	remap(proj);
	draw(proj, map);
	struct_del(grid, proj);
}

/*t_coor	*find_origin(t_map *map)
{
	t_coor	*coor;

	coor = (t_coor *)malloc(sizeof(t_coor));
	if (map->y <= 10 && map->x <= 14)
	{
		coor->interval = 50;
		coor->x = 400 - map->x / 2 * coor->interval;
		coor->y = 300 - map->y / 2 * coor->interval;
	}
	else if (map->x > map->y && map->x > 14)
	{
		coor->interval = 700 / map->x;
		coor->x = 50;
		coor->y = 300 - map->y / 2 * coor->interval;
	}
	else
	{
		coor->interval = 500 / map->y;
		coor->x = 400 - map->x / 2 * coor->interval;
		coor->y = 50;
	}
	return (coor);
}

void	draw_right(t_ptr *ptrs, t_coor *coor, t_map *map)
{
	int i;

	i = coor->x + 1;
	while (i != coor->x + coor->interval)
	{
		mlx_pixel_put(ptrs->mlx, ptrs->win, i, coor->y, 0x00FFFFFF);
		i++;
	}
}

void	draw_down(t_ptr *ptrs, t_coor *coor, t_map *map)
{
	int i;

	i = coor->y + 1;
	while (i != coor->y + coor->interval)
	{
		mlx_pixel_put(ptrs->mlx, ptrs->win, coor->x, i, 0x00FFFFFF);
		i++;
	}
}

void	draw(t_ptr *ptrs, t_map *map)
{
	t_coor *coor;
	int i;
	int j;
	int save;

	coor = find_origin(map);
	save = coor->x;
	i = 0;
	while (i < map->y)
	{
		j = 0;
		coor->x = save;
		while (j < map->x && map->mat[i][j] >= 0)
		{
			mlx_pixel_put(ptrs->mlx, ptrs->win, coor->x, coor->y, 0x00FFFFFF);
			if (++j < map->x && map->mat[i][j] >= 0)
				draw_right(ptrs, coor, map);
			if (i + 1 < map->y)
				draw_down(ptrs, coor, map);
			coor->x += coor->interval;
		}
		i++;
		coor->y += coor->interval;
	}
	free(coor);
}*/

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

int		escape_key(int key, t_map *map)
{
	if (key == 53)
	{
		map_del(map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	void	*mlx;
	void	*win;

	map = get_matrix(argc, argv);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "FdF");
	find_vertices(mlx, win, map);
	mlx_key_hook(win, escape_key, map);
	mlx_loop(mlx);
	return (0);
}
