/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:39:41 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 15:39:55 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_power(unsigned int base, int power)
{
	unsigned int	result;

	result = base;
	if (power == 0)
		return (1);
	else
		result *= ft_power(base, power - 1);
	return (result);
}
