/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:43:36 by bchan             #+#    #+#             */
/*   Updated: 2018/03/02 13:03:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pull_ldouble(t_print *form, va_list ap, int c)
{
	long double	arg;
	char		*result;

	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G')
	{
		arg = va_arg(ap, long double);
		result = ft_dtoa(arg, 0);
		result = modify_string(form, result);
		return (result);
	}
	return (length_none(form, ap, c));
}

char	*pull_ssizet(t_print *form, va_list ap)
{
	ssize_t arg;
	char	*result;

	arg = va_arg(ap, ssize_t);
	result = ft_max_itoa(arg);
	result = modify_string(form, result);
	return (result);
}

char	*pull_sizet(t_print *form, va_list ap, char c)
{
	size_t		arg;
	char		*result;
	int			i;

	arg = va_arg(ap, size_t);
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

char	*pull_sizetp(t_print *form, va_list ap)
{
	size_t		*arg;

	arg = va_arg(ap, size_t *);
	*arg = form->printed;
	return (ft_strdup(""));
}

char	*length_z(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_ssizet(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_sizet(form, ap, c));
	if (c == 'n')
		return (pull_sizetp(form, ap));
	return (length_none(form, ap, c));
}
