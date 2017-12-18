/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:40:23 by bchan             #+#    #+#             */
/*   Updated: 2017/12/15 16:50:58 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	char_check(char *tetrimino)
{
	int		i;

	i = 0;
	while (tetrimino[i])
	{
		if (tetrimino[i] != '\n' && tetrimino[i] != '#'
				&& tetrimino[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	height_check(char *tetrimino)
{
	int	line_count;
	int	i;

	line_count = 0;
	i = 0;
	while (tetrimino[i])
	{
		if (tetrimino[i] == '\n')
			line_count++;
		i++;
	}
	if (line_count == 4)
		return (1);
	else
		return (0);
}

int	width_check(char *tetrimino)
{
	int	width_count;
	int	i;

	width_count = 0;
	i = 0;
	while (tetrimino[i])
	{
		if (tetrimino[i] != '\n')
			width_count++;
		else
		{
			if (width_count != 4)
				return (0);
			else
				width_count = 0;
		}
		i++;
	}
	return (1);
}

int	block_number_check(char *tetrimino)
{
	int	block_count;
	int	i;

	block_count = 0;
	i = 0;
	while (tetrimino[i])
	{
		if (tetrimino[i] == '#')
			block_count++;
		i++;
	}
	if (block_count != 4)
		return (0);
	else
		return (1);
}

int	check_file(char *tetri)
{
	if (char_check(tetri))
		return (1);
	if (height_check(tetri))
		return (1);
	if (width_check(tetri))
		return (1);
	if (block_number_check(tetri))
		return (1);
	return (0);
}
