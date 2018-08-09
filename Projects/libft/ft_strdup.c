/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:01:43 by bchan             #+#    #+#             */
/*   Updated: 2017/11/30 14:16:09 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identical to the libc function strdup(). The function will return a pointer
** to a new duplicate string of the string s1. The duplicated string is
** allocated memory with malloc() and can be freed with free(). If there is
** insufficient memory to hold the duplicated string, NULL is returned.
*/

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen(s1) + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
