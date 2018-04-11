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

int		main(int argc, char **argv)
{
	t_map	*map;
	void	*mlx;
	void	*win;

	if (argc > 2)
		ft_putendl("Error: Too many arguments");
	else
	{
		map = get_matrix(argc, argv);
		if (map)
		{
			mlx = mlx_init();
			win = mlx_new_window(mlx, 800, 800, "FdF");
			find_vertices(mlx, win, map);
			mlx_key_hook(win, escape_key, map);
			mlx_loop(mlx);
		}
	}
	return (0);
}
