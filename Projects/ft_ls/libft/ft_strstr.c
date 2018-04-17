/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:28:37 by bchan             #+#    #+#             */
/*   Updated: 2017/12/05 13:06:21 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (little[j])
		{
			if (big[i + j] != little[j])
			{
				found = 0;
				break ;
			}
			found = 1;
			j++;
		}
		if (found == 1)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
