/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:43:25 by bchan             #+#    #+#             */
/*   Updated: 2017/10/28 17:17:31 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int		count;
	int		isprime;

	if (nb > 2)
	{
		while (nb < 2147483647)
		{
			count = 2;
			while (count < nb)
			{
				if (nb % count == 0)
				{
					isprime = 0;
					break ;
				}
				else
					isprime = 1;
				count++;
			}
			if (isprime == 1)
				return (nb);
			nb++;
		}
	}
	return (2);
}
