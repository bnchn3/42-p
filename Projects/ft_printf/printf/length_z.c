/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:43:36 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:43:57 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_z(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_sizet(form, ap));
	if (c == 'n')
		return (pull_sizetp(form, ap));
	return (length_none(form, ap, c));
}
