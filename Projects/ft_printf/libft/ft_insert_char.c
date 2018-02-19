/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:38:50 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 15:39:34 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_char(char *s, char c, int index)
{
	char	*temp;
	int		i;
	int		j;

	temp = ft_strnew(ft_strlen(s) + 1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (j == index)
			temp[j++] = c;
		temp[j++] = s[i++];
	}
	ft_strdel(&s);
	s = temp;
	return (s);
}
