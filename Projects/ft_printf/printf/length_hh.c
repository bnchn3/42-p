/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_hh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:37:34 by bchan             #+#    #+#             */
/*   Updated: 2018/02/16 16:15:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pull_char(t_print *form, va_list ap)
{
	char	arg;
	char	*result;

	arg = va_arg(ap, int);
	result = ft_itoa((int)arg);
	result = modify_string(form, result);
	return (result);
}

char	*pull_un_char(t_print *form, va_list ap, char c)
{
	unsigned char	arg;
	char			*result;
	int				i;

	arg = va_arg(ap, unsigned int);
	if (c == 'u')
		result = ft_unsigned_itoa(arg);
	if (c == 'o')
		result = ft_octal_convert(arg);
	if (c == 'x')
		result = ft_hex_convert(arg);
	if (c == 'X')
	{
		i = 0;
		result = ft_hex_convert(arg);
		while (result[i])
		{
			result[i] = (char)ft_toupper(result[i]);
			i++;
		}
	}
	result = modify_string(form, result);
	return (result);
}

char	*pull_charp(t_print *form, va_list ap)
{
	signed char		*arg;

	arg = va_arg(ap, signed char *);
	*arg = form->printed;
	return (ft_strdup(""));
}

char	*length_hh(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_char(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_char(form, ap, c));
	if (c == 'n')
		return (pull_charp(form, ap));
	return (length_none(form, ap, c));
}
