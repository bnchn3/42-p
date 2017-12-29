/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:56:15 by bchan             #+#    #+#             */
/*   Updated: 2017/12/28 16:48:26 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_four(char **tetri)
{
	int	i;

	i = 0;
	while(tetri[i])
	{
		free(tetri[i]);
		i++;
	}
	free(tetri);
}

/*
** This function helps us recognize the '.' characters that we need to include
** in the tetrimino we grab with pull_tetri.
*/

int         hashcount(char **tetri, int i, int j)
{
	int count;

	count = 0;
	if (tetri[i][j] == '#')
		return (count);
	if (i < 3 && tetri[i + 1][j] == '#')
		count++;
	if (i > 0 && tetri[i - 1][j] == '#')
		count++;
	if (j > 0 && tetri[i][j - 1] == '#')
		count++;
	if (j < 3 && tetri[i][j + 1] == '#')
		count++;
	return (count);
}

int         adj_hashcount(char **tetri, int i, int j)
{
	int count;

	count = 0;
	if (i < 3 && hashcount(tetri, i + 1, j) == 2)
		count++;
	if (i > 0 && hashcount(tetri, i - 1, j) == 2)
		count++;
	if (j > 0 && hashcount(tetri, i, j - 1) == 2)
		count++;
	if (j < 3 && hashcount(tetri, i, j + 1) == 2)
		count++;
	return (count);
}

/*
** This function will take a 2D array and a string, and copy only the 
** tetrimino (ignoring all whitespace) from the 2D array to the string. This
** will pull only the first tetrimino pointed at in the 2D array. It will
** then convert the string into a 2D array with ft_strsplit and return
** that result.
*/

char		**pull_tetri(char **tetri, char *tmp)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '.' && hashcount(tetri, i, j) + adj_hashcount(tetri, i, j) == 2)
				tmp[k++] = '.';
			if (tetri[i][j] == '#')
				tmp[k++] = '#';
			j++;
		}
		tmp[k++] = '\n';
		i++;
	}
	tmp[k] = '\0';
	return (ft_strsplit(tmp, '\n'));
}

/*
** This function will take the string made by reading the input file and
** simplify all the tetriminos by removing whitespaces and changing the
** string into a 3D array (split by whitespace, then pointers to the start
** of each tetrimino). All memory except for the final array is freed in
** this function.
*/

char		***simplify_tetri(char ***tetrimino, char *tetri)
{
	char	*tmp;
	char	**tmp2;
	char	**tmp3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp2 = ft_strsplit(tetri, '\n');
	free(tetri);
	while (tmp2[i])
	{
		tmp = (char *)malloc(9);
		tmp3 = pull_tetri(&(tmp2[i]), tmp);
		free(tmp);
		tetrimino[j] = tmp3;
		i += 4;
		j++;
	}
	free_four(tmp2);
	tetrimino[j] = NULL;
	return (tetrimino);
}

/*
** This function will create the 2D array that will be used to test
** the different permutations of tetriminos. It will call upon the 
** max_length and max_width functions to create a square that should fit
** every permutation possible.
*/

char		**create_test(int x, int y)
{
	char	**test;
	int		i;

	test = (char **)malloc(sizeof(char *) * y + 1);
	i = 0;
	while(i < y)
	{
		test[i] = (char *)malloc(y + 1);
		test[i] = (char *)ft_memset(test[i], '.', x);
		test[i][x] = '\0';
		i++;
	}
	test[i] = NULL;
	return (test);
}

void		print_square(char *tetri)
{
	int		*order;
	char	***tetrimino;
	int		i;
	int		count;

	count = tetcount(tetri);
	order = (int *)malloc(sizeof(int) * (count + 2));
	tetrimino = (char ***)malloc(sizeof(char **) * (count + 1));
	if (tetrimino && order)
	{
		order = create_order(order, count);
		tetrimino = simplify_tetri(tetrimino, tetri);
		printer(tetrimino, order, count);
		i = 0;
		while (tetrimino[i])
		{
			ft_memdel((void **)tetrimino[i]);
			i++;
		}
		free(tetrimino);
		free(order);
	}
}
