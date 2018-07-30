/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:06:53 by bchan             #+#    #+#             */
/*   Updated: 2017/12/26 13:07:04 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpchar(char **destination, char c)
{
	char	*string;

	string = ft_strdup("a");
	string[0] = c;
	ft_strpstr(destination, string);
	ft_strdel(&string);
}
