/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:47:57 by bchan             #+#    #+#             */
/*   Updated: 2018/03/12 12:57:02 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../get_next_line/get_next_line.h"

typedef struct		s_vec
{
	double	x;
	double	y;
	double	z;
}					t_vec;

typedef struct		s_ptr
{
	void *mlx;
	void *win;
	void *img;
}					t_ptr;

typedef struct		s_coor
{
	int x;
	int y;
	int interval;
}					t_coor;

typedef struct		s_map
{
	int	**mat;
	int	x;
	int	y;
	int interval;
}					t_map;

#endif
