/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:07:17 by bchan             #+#    #+#             */
/*   Updated: 2017/12/26 13:07:26 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpstr(char **destination, char *source)
{
	char	*new;

	new = ft_strjoin(*destination, source);
	ft_strdel(destination);
	*destination = new;
}
