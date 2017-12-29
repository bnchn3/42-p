/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_by_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:44:36 by bchan             #+#    #+#             */
/*   Updated: 2017/12/28 13:35:02 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_block_connected(char *file, int tetrimino_index, int index)
{
	file += tetrimino_index * 21;
	if (index / 5 > 0)
	{
		if (file[index - 5] == '#')
			return (1);
	}
	if (index / 5 < 3)
	{
		if (file[index + 5] == '#')
			return (1);
	}
	if (index % 5 < 3)
	{
		if (file[index + 1] == '#')
			return (1);
	}
	if (index % 5 > 0)
	{
		if (file[index - 1] == '#')
			return (1);
	}
	return (0);
}

int     are_blocks_connected(char *file)
{
	int index;
	int tetrimino_index;

	tetrimino_index = 0;
	while (tetrimino_index < check_line_count(file))
	{
		index = 0;
		while (index < 21)
		{
			if (file[tetrimino_index * 21 + index]
					== '#')
			{
				if (is_block_connected(file, tetrimino_index,
							index) == 0)
					return (0);
			}
			index++;
		}
		tetrimino_index++;
	}
	return (1);
}
