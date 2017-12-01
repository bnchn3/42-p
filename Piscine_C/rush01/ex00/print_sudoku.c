/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:03:44 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:12:08 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** This function will print the sudoku puzzle to the standard output. It does
** this by going through the array and using ft_putchar to print each
** character. Since the sudoku array is an integer array, we need to add 48
** (the ASCII code for '0') in order to change our integers into characters
** that we can print.
*/

void	print_sudoku(int sudoku[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (j != 8)
			{
				ft_putchar(sudoku[i][j] + 48);
				ft_putchar(' ');
			}
			else
			{
				ft_putchar(sudoku[i][j] + 48);
				ft_putchar('\n');
			}
			j++;
		}
		i++;
	}
}
