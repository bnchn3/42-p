/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:40:41 by bchan             #+#    #+#             */
/*   Updated: 2018/02/19 12:56:27 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pull_long(t_print *form, va_list ap)
{
	long	arg;
	char	*result;

	arg = va_arg(ap, long);
	result = ft_max_itoa(arg);
	result = modify_string(form, result);
	return (result);
}

char	*pull_un_long(t_print *form, va_list ap, char c)
{
	unsigned long	arg;
	char			*result;
	int				i;

	arg = va_arg(ap, unsigned long);
	if (c == 'u' || c == 'U')
		result = ft_unsigned_itoa(arg);
	if (c == 'o' || c == 'O')
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

char	*pull_wint(t_print *form, va_list ap)
{
	wchar_t arg;
	char	*result;

	arg = (wchar_t)va_arg(ap, wint_t);
	result = wchar_dup(arg);
	result = modify_string(form, result);
	return (result);
}

char	*pull_wchar(t_print *form, va_list ap)
{
	wchar_t *arg;
	char	*result;

	arg = va_arg(ap, wchar_t *);
	result = wstr_dup(arg);
	result = modify_string(form, result);
	return (result);
}

char	*length_l(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (pull_long(form, ap));
	if (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		return (pull_un_long(form, ap, c));
	if (c == 'c' || c == 'C')
		return (pull_wint(form, ap));
	if (c == 's' || c == 'S')
		return (pull_wchar(form, ap));
	if (c == 'n')
		return (pull_longp(form, ap));
	return (length_none(form, ap, c));
}
