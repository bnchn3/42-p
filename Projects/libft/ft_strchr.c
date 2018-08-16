/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:19:31 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 17:24:22 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function strchr(). The function will scan the string s
** for the character c and return a pointer to the first matching character. If
** c is not found in the string, the function returns NULL.
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			ptr = (char *)&s[i];
			break ;
		}
		i++;
	}
	if (c == 0)
		ptr = (char *)&s[i];
	return (ptr);
}
