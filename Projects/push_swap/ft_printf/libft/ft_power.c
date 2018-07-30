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

long double	ft_power(long double base, int power)
{
	long double	result;

	result = base;
	if (power == 0)
		return (1);
	else
		result *= ft_power(base, power - 1);
	return (result);
}
