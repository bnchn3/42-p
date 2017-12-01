/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:31:59 by bchan             #+#    #+#             */
/*   Updated: 2017/11/15 12:35:32 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int i;
	int nbr;

	nbr = 0;
	i = 0;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	return (nbr);
}

int		check_obstacle(char **str, int y, int x)
{
	if (!str[y] || str[y][x] == str[0][ft_strlen(str[0]) - 2] ||
			str[y][x] == '\n')
		return (1);
	return (0);
}
