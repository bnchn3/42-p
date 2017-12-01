/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:59:25 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:16:42 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** This function compares the two sudoku answers calculated from
** the front and back. If they are different, returns 1, which means
** the sudoku has more than 1 possible solution.
*/

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int s1_len;
	int s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len == s2_len)
	{
		while (s1[i] != '\0')
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (1);
		}
		return (0);
	}
	else
		return (1);
}
