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

/*int		*int_convert(char **temp)
{
	int	i;
	int	*result;

	i = 0;
	while (temp[i])
		i++;
	result = (int *)malloc(sizeof(int) * (i + 1));
	i = 0;
	while (temp[i])
		result[i] = ft_atoi(temp[i++]);
	result[i] == -1;
	return (result);
}

int		**matrix_alloc(int fd)
{
	char	buf[1];
	int		ret;
	int		**matrix;
	int		i;

	i = 1;
	while (ret = read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			i++;
	}
	matrix = (int **)malloc(sizeof(int *) * (i + 1));
	matrix[i] = NULL;
	close(fd);
	return (matrix);
}

int		**get_matrix(int argc, char **argv)
{
	int 	i;
	int		fd;
	char	*line;
	char	**temp;
	int		**matrix;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	matrix = matrix_alloc(fd);
	fd = open(argv[1], O_RDONLY);
	while (argc)
	{
		argc = get_next_line(fd, &line);
		temp = ft_strsplit(line, ' ');
		matrix[i++] = int_convert(temp);
	}
	ft_strdel(&line);
	while (temp)
	{
		if (*temp)
			free(*temp);
		temp++;
	}
	free(temp);
	return (matrix);
}

void	draw(void *mlx_ptr, void *win_ptr, int **matrix)
{

}*/

int		escape_key(int key, void **param)
{
	if (key == 53)
		mlx_destroy_window((void *)param[0], (void *)param[1]);
	return (0);
}

int		main(int argc, char **argv)
{
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	void	**ptrs;

	//matrix = get_matrix(argc, argv);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FdF");
	ptrs = (void **)malloc(sizeof(void *) * 2);
	ptrs[0] = mlx_ptr;
	ptrs[1] = win_ptr;
	//draw(mlx_ptr, win_ptr, matrix);
	mlx_key_hook(win_ptr, escape_key, ptrs);
	mlx_loop(mlx_ptr);
	return (0);
}
