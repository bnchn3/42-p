/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:40:23 by bchan             #+#    #+#             */
/*   Updated: 2017/12/13 13:40:41 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_box(char ***tetri)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j][0] != '\0')
		{
			if (j > 3)
				return (0);
			k = 0;
			while (tetri[i][j][k])
			{
				if (k > 3 || (tetri[i][j][k] != '.' && tetri[i][j][k] != '#'))
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_tetri(char ***tetri)
{
	

int			check_file(char ***tetri)
{
	if (check_box(tetri))
		return (1);
	if (check_tetri(tetri))
		return (1);
	return (0);
}
