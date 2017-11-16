/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:00:43 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/08 11:07:49 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** The following function copies the lines (strings) sent in as parameters
** when the code is firstly run and saves the values into an int[][]. The
** reason behind this is because it makes it easier for comparing the
** conditions after a number has been put inside a box.
*/

void	write_sudoku(char **argv, int sudoku[9][9])
{
	int	i;
	int	j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				sudoku[i - 1][j] = 0;
			else
				sudoku[i - 1][j] = argv[i][j] - 48;
			j++;
		}
		i++;
	}
}

/*
** The main function calls write_sudoku, which creates the new int[][],
** (see above) and then it solves the sudoku from the top and then from
** the bottom. It then compares both answers. If they are the same, sudoku
** has 1 unique solution and prints it. Otherwise, prints "Error".
*/

int		main(int argc, char **argv)
{
	int sudoku[9][9];
	int sudoku2[9][9];

	if (initial_check(argc, argv))
	{
		write_sudoku(argv, sudoku);
		write_sudoku(argv, sudoku2);
		solve_sudoku(sudoku, 0, 0);
		solve_sudoku_back(sudoku2, 8, 8);
		if (sudoku_compare(sudoku, sudoku2) == 0)
			print_sudoku(sudoku);
		else
			ft_putstr("Error");
		ft_putchar('\n');
	}
	else
		ft_putstr("Error");
	ft_putchar('\n');
	return (0);
}
