/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:56:15 by bchan             #+#    #+#             */
/*   Updated: 2017/12/18 14:09:03 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function will take a 2D array and a string, and copy only the 
** tetrimino (ignoring all whitespace) from the 2D array to the string. This
** will pull only the first tetrimino pointed at in the 2D array. It will
** then convert the string into a 2D array with ft_strsplit and return
** that result.
*/

char		**pull_tetri(char **four_by_four, char *tmp)
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
			if (four_by_four[i][j] == '#')
			{
				tmp[k] = '#';
				k++;
			}
			j++;
		}
		if (tmp[k - 1] == '#')
			tmp[k++] = '\n';
		i++;
	}
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
		tmp = (char *)malloc(7);
		tmp3 = pull_tetri(tmp2[i], tmp);
		free(tmp);
		tetrimino[j] = &(tmp3);
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

char		**create_test(***tetrimino)
{
	char	**test;
	int		i;

	test = (char **)malloc(sizeof(char *) * max_length(tetrimino) + 1);
	test[max_length(tetrimino)] = NULL;
	i = 0;
	while(test[i])
	{
		test[i] = (char *)malloc(max_width(tetrimino) + 1);
		test[max_width(tetrimino)] = '\0';
		i++;
	}
	return (test);
}

void		print_square(char *tetri)
{
	int		*order;
	char	***tetrimino;
	int		i;

	order = (int *)malloc(sizeof(int) * tetcount(tetri) + 1);
	tetrimino = (char ***)malloc(sizeof(char **) * tetcount(tetri) + 1);
	if (tetrimino && order)
	{
		order[tetcount(tetri)] = 0;
		tetrimino = simplify_tetri(tetrimino, tetri);
		printer(tetrimino);
		i = 0;
		while (tetrimino[i])
		{
			free_four(tetrimino[i]);
			i++;
		}
		free(tetrimino);
	}
}
