/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:18:46 by bchan             #+#    #+#             */
/*   Updated: 2017/10/29 13:07:42 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush_inner(int x, int y, int row, int column)
{
	if (row == 0 && column == 0)
		ft_putchar('/');
	else if (row == 0 && column == x - 1)
		ft_putchar('\\');
	else if (row == y - 1 && column == 0)
		ft_putchar('\\');
	else if (row == y - 1 && column == x - 1)
		ft_putchar('/');
	else if (row != 0 && row != y - 1 && column != 0 && column != x - 1)
		ft_putchar(' ');
	else
		ft_putchar('*');
}

void	rush(int x, int y)
{
	int row;
	int column;

	row = 0;
	while (row < y)
	{
		column = 0;
		while (column < x)
		{
			rush_inner(x, y, row, column);
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
