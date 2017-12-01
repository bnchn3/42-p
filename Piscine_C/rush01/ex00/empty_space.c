/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:02:27 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:11:08 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function will check if the number you want to put in the square will
** violate any of the sudoku rules. It will check the row, column, and square
** to see if any of them contain another copy of num. If a copy is found in
** any of these cases, the function returns 0, otherwise it will return 1.
*/

int	empty_space(int sudoku[9][9], int row, int col, int num)
{
	int i;
	int row_start;
	int col_start;

	i = 0;
	row_start = (row / 3) * 3;
	col_start = (col / 3) * 3;
	while (i < 9)
	{
		if (sudoku[row][i] == num)
			return (0);
		if (sudoku[i][col] == num)
			return (0);
		if (sudoku[row_start + (i % 3)][col_start + (i / 3)] == num)
			return (0);
		i++;
	}
	return (1);
}
