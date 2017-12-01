/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:03:05 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:11:49 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** This function will check if the arguments provided through the command line
** meet the standards for correct input. First it will check if there are
** 10 items in the argv array (9 arguments + program name). It then checks if
** each argument contains 9 characters. Finally, it will check if each argument
** contains valid characters (numbers 1-9 or '.'). If any of these steps are
** failed, the function returns a 0. Otherwise, it will return a 1.
*/

int	initial_check(int arguments, char **array)
{
	int i;
	int j;

	i = 1;
	if (arguments != 10)
		return (0);
	while (i < 10)
	{
		if (ft_strlen(array[i]) != 9)
			return (0);
		i++;
	}
	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (array[i][j] != 46 && (array[i][j] < 49 || array[i][j] > 57))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
