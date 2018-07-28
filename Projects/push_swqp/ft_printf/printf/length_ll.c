/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:41:42 by bchan             #+#    #+#             */
/*   Updated: 2018/02/19 12:56:59 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pull_long_long(t_print *form, va_list ap)
{
	long long	arg;
	char		*result;

	arg = va_arg(ap, long long);
	result = ft_max_itoa(arg);
	result = modify_string(form, result);
	return (result);
}

char	*pull_un_long_long(t_print *form, va_list ap, char c)
{
	unsigned long long	arg;
	char				*result;
	int					i;

	arg = va_arg(ap, unsigned long long);
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

char	*pull_longp(t_print *form, va_list ap)
{
	long		*arg;

	arg = va_arg(ap, long *);
	*arg = form->printed;
	return (ft_strdup(""));
}

char	*pull_long_longp(t_print *form, va_list ap)
{
	long long		*arg;

	arg = va_arg(ap, long long *);
	*arg = form->printed;
	return (ft_strdup(""));
}

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
