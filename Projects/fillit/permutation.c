/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:57:25 by bchan             #+#    #+#             */
/*   Updated: 2017/12/29 15:51:42 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function is basically memcpy but for a 2D array. It will copy the src
** array (the tetrimino to be placed) into the dest array at the coordinates
** pointed at by coor. It takes a character as an argument so that we can
** specify later what to put into our dest array.
*/

void	twod_memcpy(char **dest, char **src, t_coor *coor, char c)
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
				dest[x][y] = c;
			y++;
		}
		x++;
		i++;
	}
	free(coor);
}

/*
** A simple function to malloc and initialize a t_coor struct.
*/

t_coor	*create_coor(void)
{
	t_coor	*coor;

	coor = (t_coor *)malloc(sizeof(t_coor));
	if (coor)
	{
		coor->row = 0;
		coor->col = 0;
	}
	return (coor);
}

t_coor	*set_coor(t_coor *coor, int x, int y)
{
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

void	place_tetri(char **dest, char **src, t_coor *coor, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i][j] && dest[j][i])
	{
		i = 0;
		while (i <= j)
		{
			if (check_place(dest, src, i, j))
			{
				coor = set_coor(coor, i, j);
				twod_memcpy(dest, src, coor, c);
				return ;
			}
			if (check_place(dest, src, j, i))
			{
				coor = set_coor(coor, j, i);
				twod_memcpy(dest, src, coor, c);
				return ;
			}
			i++;
		}
		j++;
	}
}

int		perm_dimen(char **test)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while(test[i])
	{
		j = 0;
		while(test[i][j])
		{
			if (test[i][j] != '.' && j > count)
				count = j;
			if (test[i][j] != '.' && i > count)
				count = i;
			j++;
		}
		i++;
	}
	return (count + 1);
}

int		test_perm(char ***tetrimino, int *order, int dimen)
{
	int		i;
	char	**test;
	t_coor	*coor;

	i = 1;
	test = create_test(max_length(tetrimino), max_width(tetrimino));
	while(order[i] && test)
	{
		coor = create_coor();
		place_tetri(test, tetrimino[order[i] - 1], coor, '#');
		i++;
	}
	if (perm_dimen(test) < dimen)
		dimen = perm_dimen(test);
	free_four(test);
	return (dimen);
}

int		*create_order(int *order, int count)
{
	int		i;
	int		num;

	i = 1;
	num = 1;
	order[0] = 104;
	while(i <= count)
	{
		order[i] = num;
		num++;
		i++;
	}
	order[i] = 0;
	return (order);
}

void	*int_memcpy(int *dst, int *src, size_t n)
{
	size_t				i;
	int		*ptr;
	int		*ptr2;

	i = 0;
	ptr = dst;
	ptr2 = src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}

void	swap(int *order, int i, int j)
{
	int	temp;

	temp = order[i];
	order[i] = order[j];
	order[j] = temp;
}

int     descending(int *order, int end)
{
	int i;

	i = 1;
	while (i < end)
	{
		if (order[i] < order[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int     find_ceiling(int *order, int lowest, int end)
{
	int i;
	int result;

	i = lowest;
	result = lowest;
	while(i <= end)
	{
		if (order[i] > order[lowest])
		{
			result = i;
			break ;
		}
		i++;
	}
	i = result;
	while(i <= end)
	{
		if ((order[result] > order[i]) && (order[i] > order[lowest]))
			result = i;
		i++;
	}
	return (result);
}

void    sort(int *order, int start, int end)
{
	int i;

	i = start;
	while(i < end)
	{
		if (order[i] > order[i + 1])
		{
			swap(order, i, i + 1);
			i = start;
		}
		i++;
	}
}

int     *permute(char ***tetrimino, int *order, int end)
{
	int *temp;
	int i;
	int lowest;

	temp = (int *)malloc(sizeof(int) * (end + 2));
	temp = int_memcpy(temp, order, end + 2);
	temp[0] = test_perm(tetrimino, temp, temp[0]);
	if (temp[0] < order[0])
		int_memcpy(order, temp, end + 2);
	while(!(descending(temp, end)))
	{	
		i = 1;
		while(i < end)
		{
			if (temp[i] < temp[i + 1])
				lowest = i;
			i++;
		}
		i = find_ceiling(temp, lowest, end);
		if (i == lowest)
			break ;
		swap(temp, i, lowest);
		sort(temp, lowest + 1, end);
		temp[0] = test_perm(tetrimino, temp, temp[0]);
		if (temp[0] < order[0])
			int_memcpy(order, temp, end + 2);
	}
	free (temp);
	return (order);
}

void	final_print(char **final)
{
	int		i;
	int		j;

	i = 0;
	while(final[i])
	{
		j = 0;
		while(final[i][j])
		{
			ft_putchar(final[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	printer(char ***tetrimino, int *order, int count)
{
	int 	i;
	char	**final;
	t_coor	*coor;

	i = 1;
	order = permute(tetrimino, order, count);
	final = create_test(order[0], order[0]);
	while(i <= count && final)
	{
		coor = create_coor();
		place_tetri(final, tetrimino[order[i] - 1], coor, order[i] + 64);
		i++;
	}
	final_print(final);
	free_four(final);
}
