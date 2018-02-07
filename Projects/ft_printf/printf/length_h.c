/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:39:40 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:40:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pull_short(t_print *form, va_list ap)
{
	short	arg;
	char	*result;

	arg = va_arg(ap, short);
	result = ft_itoa((int)arg);
	result = modify_string(form, result);
	return (result);
}

char	*pull_un_short(t_print *form, va_list ap, char c)
{
	unsigned short	arg;
	char			*result;

	arg = va_arg(ap, unsigned short);
	if (c == 'u')
		result = ft_unsigned_itoa((unsigned int)arg);
	if (c == 'o')
		result = ft_octal_convert((unsigned int)arg);
	if (c == 'x')
		result = ft_hex_convert((unsigned int)arg);
	if (c == 'X')
	{
		i = 0;
		result = ft_hex_convert((unsigned int)arg);
		while (result[i])
		{
			result[i] = (char)ft_toupper(result[i]);
			i++;
		}
	}
	result = modify_string(form, result);
	return (result);
}

char	*length_h(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_short(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_short(form, ap, c));
	if (c == 'n')
		return (pull_shortp(form, ap));
	return (length_none(form, ap, c));
}