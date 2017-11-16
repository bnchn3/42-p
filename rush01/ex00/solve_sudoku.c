/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:01:14 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:12:31 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** The following function places a digit inside a square.
** After checking the conditions (empty_space), it calls
** the solve_sudoku function recursively. If it can't find a
** valid number to place, it places a 0 and it back tracks.
*/

int	place_digit(int sudoku[9][9], int row, int col, int i)
{
	while (i < 9)
	{
		if (empty_space(sudoku, row, col, i + 1))
		{
			sudoku[row][col] = i + 1;
			if ((col + 1) < 9)
			{
				if (solve_sudoku(sudoku, row, col + 1))
					return (1);
				else
					sudoku[row][col] = 0;
			}
			else if ((row + 1) < 9)
			{
				if (solve_sudoku(sudoku, row + 1, 0))
					return (1);
				else
					sudoku[row][col] = 0;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

/*
** This function solves the sudoku by recursion. This function
** solves the sudoku starting from the top and moving to the bottom.
** If the value is 0 at the current square (meaning it hasn't
** been assigned a value), it calls place_digit (see above).
** Otherwise, depending on the position, it calls itself again recursively.
*/

int	solve_sudoku(int sudoku[9][9], int row, int col)
{
	if (row < 9 && col < 9)
	{
		if (sudoku[row][col] != 0)
		{
			if ((col + 1) < 9)
				return (solve_sudoku(sudoku, row, col + 1));
			else if ((row + 1) < 9)
				return (solve_sudoku(sudoku, row + 1, 0));
			else
				return (1);
		}
		else
		{
			return (place_digit(sudoku, row, col, 0));
		}
		return (0);
	}
	else
		return (1);
}
