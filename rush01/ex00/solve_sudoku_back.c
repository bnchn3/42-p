/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:04:15 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:12:52 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** The following function places a digit inside a square. The
** difference between this one and the previous function
** (place_digit) is that this one starts from the back of the
** puzzle. After checking the conditions (empty_space), it calls
** the solve_sudoku_back function recursively. If it can't find a
** valid number to place, it places a 0 and it back tracks.
*/

int	place_digit_back(int sudoku[9][9], int row, int col, int i)
{
	while (i > 0)
	{
		if (empty_space(sudoku, row, col, i))
		{
			sudoku[row][col] = i;
			if ((col - 1) >= 0)
			{
				if (solve_sudoku_back(sudoku, row, col - 1))
					return (1);
				else
					sudoku[row][col] = 0;
			}
			else if ((row - 1) >= 0)
			{
				if (solve_sudoku_back(sudoku, row - 1, 8))
					return (1);
				else
					sudoku[row][col] = 0;
			}
			else
				return (1);
		}
		i--;
	}
	return (0);
}

/*
** This function solves the sudoku by recursion. The difference
** between this function and its counter-part (solve_sudoku) is that
** this function solves the sudoku starting from the bottom and making
** its way back to the top. If the value is 0 at the current square
** (meaning it hasn't been assigned a value), it calls place_digit_back
** (see above). Otherwise, depending on the position, it calls itself
** again recursively.
*/

int	solve_sudoku_back(int sudoku[9][9], int row, int col)
{
	if (row >= 0 && col >= 0)
	{
		if (sudoku[row][col] != 0)
		{
			if ((col - 1) >= 0)
				return (solve_sudoku_back(sudoku, row, col - 1));
			else if ((row - 1) >= 0)
				return (solve_sudoku_back(sudoku, row - 1, 8));
			else
				return (1);
		}
		else
		{
			return (place_digit_back(sudoku, row, col, 9));
		}
		return (0);
	}
	else
		return (1);
}
