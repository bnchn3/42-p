/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:29:29 by bchan             #+#    #+#             */
/*   Updated: 2017/10/28 17:47:46 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 0 && nb < 13)
	{
		nb *= ft_recursive_factorial(nb - 1);
		return (nb);
	}
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
