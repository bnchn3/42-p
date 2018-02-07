/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_j.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:42:55 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:43:17 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_j(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_intmax(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_uintmax(form, ap, c));
	if (c == 'n')
		return (pull_intmaxp(form, ap));
	return (length_none(form, ap, c));
}
