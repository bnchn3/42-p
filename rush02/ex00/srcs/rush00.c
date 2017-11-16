/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:07:44 by bchan             #+#    #+#             */
/*   Updated: 2017/11/11 19:59:58 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	rush00_inner(int *xy, int row, int column, char *str)
{
	int x;
	int y;

	x = xy[0];
	y = xy[1];
	if ((row == 0 || row == y - 1) && (column == 0 || column == x - 1))
		*str = 'o';
	else if (row == y - 1 || row == 0)
		*str = '-';
	else if (column == 0 || column == x - 1)
		*str = '|';
	else
		*str = ' ';
}

char	*rush00(int x, int y)
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
			rush00_inner(xy, row, column, &str[i++]);
			column++;
		}
		str[i++] = '\n';
		row++;
	}
	str[i] = '\0';
	return (str);
}
