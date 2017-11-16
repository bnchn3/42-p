/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:56:17 by bchan             #+#    #+#             */
/*   Updated: 2017/10/28 17:39:56 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	count;

	count = 1;
	while (count <= nb)
	{
		if ((nb / count == count) && (nb % count == 0))
		{
			return (count);
		}
		count++;
	}
	return (0);
}