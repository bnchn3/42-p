/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:08:47 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 16:59:07 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	found = 1;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j])
		{
			if (big[i] != little[j] || i >= len)
			{
				found = 0;
				break ;
			}
			found = 1;
			i++;
			j++;
		}
		if (found == 1)
			return ((char *)&big[i - j]);
		i++;
	}
	return (NULL);
}
