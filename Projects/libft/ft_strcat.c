/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:35:53 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 14:15:26 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function strcat(). The function will concatenate the
** string s2 onto the end of the string s1, returning a pointer to s1. The null
** terminator in s1 is overwritten and a new terminator is placed at the end of
** the concatenated string. The strings must not overlap, and s1 must have
** enough space for the result.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i])
	{
		s1[len] = s2[i];
		i++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
