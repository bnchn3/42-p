/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:21:52 by bchan             #+#    #+#             */
/*   Updated: 2017/11/15 15:25:57 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int		check_char(char **str, int y, int x)
{
	if (str[y][x] == str[0][ft_strlen(str[0]) - 1])
		return (0);
	else if (str[y][x] != str[0][ft_strlen(str[0]) - 2])
		return (0);
	return (1);
}

int		while_check(char **str)
{
	int		y;
	int		x;
	int		valid;

	y = 0;
	valid = 0;
	while (str[++y])
	{
		if (ft_strlen(str[y]) != ft_strlen(str[1]))
			return (0);
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == str[0][ft_strlen(str[0]) - 3])
				valid = 1;
			else if (check_char(str, y, x) == 0)
				return (0);
			x++;
		}
	}
	if (valid == 0)
		return (0);
	return (1);
}

int		check_map(char **str)
{
	int		i;
	int		y;

	i = ft_strlen(str[0]);
	y = 0;
	if (ft_atoi(str[0]) <= 0)
		return (0);
	if (str[0][i - 1] == str[0][i - 2] || str[0][i - 2] == str[0][i - 3] ||
			str[0][i - 1] == str[0][i - 3])
		return (0);
	if (str[0][i - 4] < '0' || str[0][i - 4] > '9')
		return (0);
	if (while_check(str) == 0)
		return (0);
	while (str[y])
		y++;
	if (y - 1 != ft_atoi(str[0]))
		return (0);
	return (1);
}
