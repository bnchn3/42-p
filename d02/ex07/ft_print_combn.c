/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:25:46 by bchan             #+#    #+#             */
/*   Updated: 2017/10/26 20:50:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print(int *nbr, int size)
{
	int		n;
	int		less;

	n = 1;
	less = 1;
	while (n < size)
	{
		if (nbr[n - 1] >= nbr[n])
			less = 0;
		n++;
	}
	if (less == 1)
	{
		n = 0;
		while (n < size)
			ft_putchar(nbr[n++] + '0');
		if (nbr[0] < (10 - size))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		number[n];

	i = 0;
	if (n == 1)
		while (i < 10)
			ft_putchar(i++ + '0');
	while (i < n)
		number[i++] = 0;
	while (number[0] <= (10 - n) && n > 1)
	{
		ft_print(number, n);
		number[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (number[i] > 9)
			{
				number[i - 1]++;
				number[i] = 0;
			}
		}
	}
}
