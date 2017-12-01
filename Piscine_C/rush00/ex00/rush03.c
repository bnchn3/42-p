/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:41:59 by bchan             #+#    #+#             */
/*   Updated: 2017/10/29 13:09:30 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

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
			if ((row == 0 || row == y - 1) && (column == 0))
				ft_putchar('A');
			else if ((row == y - 1 || row == 0) && (column == x - 1))
				ft_putchar('C');
			else if (row != y - 1 && row != 0 && column != x - 1 && column != 0)
				ft_putchar(' ');
			else
				ft_putchar('B');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
