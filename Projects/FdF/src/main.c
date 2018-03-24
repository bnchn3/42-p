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
	result = (int *)malloc(sizeof(int) * (i + 1));
	if (i > map->x)
		map->x = i;
	i = 0;
	while (temp[i])
	{
		result[i] = ft_atoi(temp[i]);
		ft_strdel(&temp[i]);
		i++;
	}
	result[i] = -1;
	free(temp);
	return (result);
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
	map->mat = (int **)malloc(sizeof(int *) * i);
	map->y = i;
	map->x = 0;
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
		map->mat[i++] = int_convert(temp, map);
	}
	ft_strdel(&line);
	return (map);
}

t_coor	*find_origin(t_map *map)
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
}

int		escape_key(int key, t_ptr *param)
{
	if (key == 53)
		mlx_destroy_window(param->mlx, param->win);
	return (0);
}

void	map_del(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y)
	{
		free(map->mat[i]);
		i++;
	}
	free(map->mat);
	free(map);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_ptr	*ptrs;

	map = get_matrix(argc, argv);
	ptrs = (t_ptr *)malloc(sizeof(t_ptr));
	ptrs->mlx = mlx_init();
	ptrs->win = mlx_new_window(ptrs->mlx, 800, 600, "FdF");
	draw(ptrs, map);
	mlx_key_hook(ptrs->win, escape_key, ptrs);
	mlx_loop(ptrs->mlx);
	free(ptrs);
	map_del(map);
	return (0);
}
