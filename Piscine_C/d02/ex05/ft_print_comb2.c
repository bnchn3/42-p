/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:12:05 by bchan             #+#    #+#             */
/*   Updated: 2017/10/26 18:31:48 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print(char a[]);
int		ft_putchar(char c);

void	ft_print_comb2(void)
{
	char	numbers[4]
	   
	numbers = {'0', '0', '0', '1'};
	while (numbers[0] != '9' || numbers[1] != '9')
	{
		ft_print(numbers);
		numbers[3]++;
		if (numbers[3] > '9')
		{
			numbers[2]++;
			numbers[3] = '0';
		}
		if (numbers[2] > '9')
		{
			numbers[2] = numbers[0];
			numbers[1]++;
			if (numbers[1] > '9')
			{
				numbers[0]++;
				numbers[1] = '0';
			}
			numbers[3] = numbers[1] + 1;
		}
	}
}

void	ft_print(char a[])
{
	ft_putchar(a[0]);
	ft_putchar(a[1]);
	ft_putchar(' ');
	ft_putchar(a[2]);
	ft_putchar(a[3]);
	if (a[0] != '9' || a[1] != '8')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
