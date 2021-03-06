/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_dimen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:15:39 by bchan             #+#    #+#             */
/*   Updated: 2017/12/28 16:37:48 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int max_width(char ***tetri)
{
	int max;
	int i;
	int j;

	max = 0;
	i = 0;
	while(tetri[i])
	{
		j = 0;
		while(tetri[i][0][j])
			j++;
		max += j;
		i++;
	}
	return(max);
}

int max_length(char ***tetri)
{
	int max;
	int i;
	int	j;

	max = 0;
	i = 0;
	while(tetri[i])
	{
		j = 0;
		while(tetri[i][j])
			j++;
		max += j;
		i++;
	}
	return(max);
}
