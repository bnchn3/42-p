/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:59:11 by bchan             #+#    #+#             */
/*   Updated: 2017/10/27 14:24:32 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_numbers(void)
{
	int		i;
	char	c;

	i = 48;
	while (i < 58)
	{
		c = i;
		ft_putchar(c);
		i++;
	}
}