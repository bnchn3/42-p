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

t_map	*matrix_alloc(int fd, int i)
{
	char	buf[1];
	int		ret;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	while ((ret = read(fd, buf, 1)))
	{
		if (ret < 0)
		{
			perror("read");
			return (NULL);
		}
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

t_map	*get_matrix(int argc, char **argv, t_map *map)
{
	int		i;
	int		fd;
	char	*line;
	char	**temp;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (NULL);
	}
	map = matrix_alloc(fd, 0);
	fd = open(argv[1], O_RDONLY);
	while (argc && argc != -1 && map)
	{
		argc = get_next_line(fd, &line);
		if (argc && argc != -1)
		{
			temp = ft_strsplit(line, ' ');
			map->mat[i++] = get_x(temp, map);
		}
		ft_strdel(&line);
	}
	return (map);
}
