/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_by_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:44:36 by bchan             #+#    #+#             */
/*   Updated: 2017/12/15 15:49:23 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_index(int index)
{
	if (0 <= index && index <= 3)
		return (1);
	else
		return (0);
}

int		check_around(char **four_by_four, int row_index,
			int column_index)
{
	int	add_to_row;
	int	add_to_column;

	add_to_row = -1;
	while (add_to_row < 2)
	{
		if (check_index(row_index + add_to_row))
		{
			add_to_column = -1;
			while (add_to_column < 2)
			{
				if (check_index(column_index + add_to_column) &&
						(add_to_column != 0 || add_to_row != 0) &&
						four_by_four[row_index][column_index] == '#')
					return (1);
				add_to_column++;
			}
		}
		add_to_row++;
	}
	return (0);
}

void	free_four(char **four_by_four)
{
	int	i;

	i = 0;
	while (four_by_four[i])
	{
		free(four_by_four[i]);
		i++;
	}
	free(four_by_four);
}

int		are_blocks_connected(char *tetri)
{
	int		row_index;
	int		column_index;
	char	**four_by_four;

	four_by_four = ft_strsplit(tetri, '\n');
	row_index = 0;
	while (four_by_four[row_index])
	{
		column_index = 0;
		while (four_by_four[row_index][column_index])
		{
			if (four_by_four[row_index][column_index] == '#'
					&& check_around(four_by_four, row_index, column_index)
					== 0)
			{
				free_four(four_by_four);
				return (0);
			}
			column_index++;
		}
		row_index++;
	}
	free_four(four_by_four);
	return (1);
}
