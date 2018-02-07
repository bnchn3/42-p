/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:40:41 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:41:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_l(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (pull_long(form, ap, c));
	if (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		return (pull_un_long(form, ap, c));
	if (c == 'c' || c == 'C')
		return (pull_wint(form, ap, c));
	if (c == 's' || c == 'S')
		return (pull_wchar(form, ap, c));
	if (c == 'n')
		return (pull_longp(form, ap, c));
	return (length_none(form, ap, c));
}
