/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:57:25 by bchan             #+#    #+#             */
/*   Updated: 2017/12/19 16:50:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function is basically memcpy but for a 2D array. It will copy the src
** array (the tetrimino to be placed) into the dest array at the coordinates
** pointed at by coor. It takes a character as an argument so that we can
** specify later what to put into our dest array.
*/

void	twod_memcpy(char **dest, char **src, t_coor coor, char c)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = coor->row;
	while(src[i])
	{
		j = 0;
		y = coor->col;
		while(src[i][j])
		{
			if (src[i][j++] == '#')
				dest[x][y++] = c;
		}
		x++;
		i++;
	}
	free(coor);
}

/*
** A simple function to malloc and initialize a t_coor struct.
*/

t_coor	set_coor(int x, int y)
{
	t_coor	coor;

	coor = (t_coor *)malloc(sizeof(t_coor));
	if (coor)
	{
		coor->row = x;
		coor->col = y;
	}
	return (coor);
}

/*
** This function will check if the tetrimino can be placed at
** the coordinates given in the arguments.
*/

int		check_place(char **dest, char **src, int x, int y)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	while(src[i])
	{
		j = 0;
		col = y;
		while(src[i][j])
		{
			if (dest[x][col] != '.' && src[i][j] != '.')
				return (0);
			col++;
			j++;
		}
		x++;
		i++;
	}
	return (1);
}

/*
** This function will go through the dest map and place the 
** tetrimino at the first position available, following a simple
** algorithm that will ensure the pieces will be in the upper left.
*/

void	place_tetri(char **dest, char **src, t_coor coor, char c)
{
	int	i;
	int	j;

	j = 0;
	while (dest[i][j] && dest[j][i])
	{
		i = 0;
		while (i <= j)
		{
			if (check_place(dest, src, i, j))
			{
				coor = set_coor(i, j);
				twod_memcpy(dest, src, coor, c);
				return ;
			}
			if (check_place(dest, src, j, i))
			{
				coor = set_coor(i, j);
				twod_memcpy(dest, src, coor, c);
				return ;
			}
			i++;
		}
		j++;
	}
}

t_coor	test_perm(char ***tetrimino)

void	printer(char ***tetrimino, order);
{
	t_coor	coor;
	t_coor	dimen;

	
