/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:41:59 by bchan             #+#    #+#             */
/*   Updated: 2017/11/11 20:11:41 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	rush03_inner(int *xy, int row, int column, char *str)
{
	int x;
	int y;

	x = xy[0];
	y = xy[1];
	if ((row == 0 || row == y - 1) && (column == 0))
		*str = 'A';
	else if ((row == y - 1 || row == 0) && (column == x - 1))
		*str = 'C';
	else if (row != y - 1 && row != 0 && column != x - 1 && column != 0)
		*str = ' ';
	else
		*str = 'B';
}

char	*rush03(int x, int y)
{
	int		row;
	int		column;
	char	*str;
	int		i;
	int		xy[2];

	xy[0] = x;
	xy[1] = y;
	i = 0;
	str = malloc(y + (y * x) + 1);
	row = 0;
	while (row < y)
	{
		column = 0;
		while (column < x)
		{
			rush03_inner(xy, row, column, &str[i++]);
			column++;
		}
		str[i++] = '\n';
		row++;
	}
	str[i] = '\0';
	return (str);
}
