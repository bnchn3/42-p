/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:41:42 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:42:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_ll(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_long_long(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_long_long(form, ap, c));
	if (c == 'n')
		return (pull_long_longp(form, ap));
	return (length_none(form, ap, c));
}
