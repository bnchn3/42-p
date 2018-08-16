/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:08:47 by bchan             #+#    #+#             */
/*   Updated: 2017/12/05 14:16:26 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function strnstr(). The function will search up to len
** characters of the string big for the substring little, returning a pointer
** to the first matching substring found. If little is not found within len
** characters, the function returns NULL. If little is an empty string, the
** function returns a pointer to big.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j])
		{
			if (big[i + j] != little[j] || (i + j) >= len)
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
