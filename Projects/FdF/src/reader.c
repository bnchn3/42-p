/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:55:13 by bchan             #+#    #+#             */
/*   Updated: 2018/04/09 15:01:35 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_x(char **temp, t_map *map)
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
	map->up = 0;
	map->left = 0;
	map->zoom = 0;
	map->color = 0x00FFFFFF;
	close(fd);
	return (map);
}

t_map	*get_matrix(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;
	char	**temp;
	t_map	*map;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (NULL);
	}
	map = matrix_alloc(fd);
	fd = open(argv[1], O_RDONLY);
	while (argc)
	{
		argc = get_next_line(fd, &line);
		temp = ft_strsplit(line, ' ');
		if (argc)
			map->mat[i++] = get_x(temp, map);
	}
	ft_strdel(&line);
	return (map);
}
