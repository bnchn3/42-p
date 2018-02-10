/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:44:29 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:44:55 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_none(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'c')
		return (pull_int(form, ap, c));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_int(form, ap, c));
	if (c == 's')
		return (pull_string(form, ap));
	if (c == 'p')
		return (pull_voidp(form, ap));
	if (c == 'n')
		return (pull_intp(form, ap));
	if (c == 'D' || c == 'U' || c == 'O' || c == 'C' || c == 'S')
		return (length_l(form, ap, c));
	return (NULL);
}
