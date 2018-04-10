/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:47:57 by bchan             #+#    #+#             */
/*   Updated: 2018/04/09 15:04:31 by bchan            ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	void	*img;
}					t_ptr;

typedef struct		s_coor
{
	double	x;
	double	y;
}					t_coor;

typedef struct		s_map
{
	char	***mat;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	int		up;
	int		left;
	int		zoom;
	int		color;
}					t_map;

t_vec				*new_vec(double x, double y, double z);
t_list				**z_convert(t_map *map);
void				rotate_grid(t_list *grid, double mid);
t_list				**project(t_list **grid);
void				fov(t_list **proj);
void				remap(t_list **proj);
void				draw(t_list **proj, t_map *map);
t_map				*get_matrix(int argc, char **argv);
void				struct_del(t_list **grid, t_list **proj);
void				map_del(t_map *map);
void				find_vertices(void *mlx, void *win, t_map *map);
int					escape_key(int key, t_map *map);
int					move_key(int key, t_map *map);
int					color_key(int key, t_map *map);

#endif
