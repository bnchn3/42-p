/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:05:28 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:17:23 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** This function will take a solved sudoku puzzle and write it to a string.
** It does this by going through each sudoku number and writing them to a
** string. This will allow us to easily compare different solutions using
** ft_strcmp.
*/

char	*sudoku_string(int sudoku[9][9], char string[82])
{
	int k;
	int i;
	int j;

	k = 0;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			string[k] = sudoku[i][j] + 48;
			k++;
			j++;
		}
		i++;
	}
	string[k] = '\0';
	return (string);
}

/*
** This function compares the two sudoku solutions we get in our main.
** It does this by using sudoku_string to convert the puzzles into strings,
** then using ft_strcmp to compare the strings for any differences. If the
** puzzle is valid (there is only one solution), then the strings should match
** but if there is more than one solution, the strings should be different.
*/

int		sudoku_compare(int sudoku1[9][9], int sudoku2[9][9])
{
	char	string1[82];
	char	string2[82];
	int		i;

	i = ft_strcmp(sudoku_string(sudoku1, string1),
			sudoku_string(sudoku2, string2));
	return (i);
}
