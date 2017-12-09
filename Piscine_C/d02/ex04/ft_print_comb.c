/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:13:23 by bchan             #+#    #+#             */
/*   Updated: 2017/10/26 17:09:21 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print(char a, char b, char c);
int		ft_putchar(char c);

void	ft_print_comb(void)
{
	char	hundreds;
	char	tens;
	char	ones;

	hundreds = '0';
	while (hundreds < '8')
	{
		tens = hundreds + 1;
		while (tens < '9')
		{
			ones = tens + 1;
			while (ones < ':')
			{
				if (hundreds != tens && hundreds != ones && tens != ones)
				{
					ft_print(hundreds, tens, ones);
				}
				ones++;
			}
			tens++;
		}
		hundreds++;
	}
}

void	ft_print(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (a < '7')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
