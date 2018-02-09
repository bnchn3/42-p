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

char	*pull_sizet(t_print *form, va_list ap, char c)
{
	size_t		arg;
	char			*result;
	int i;

	arg = va_arg(ap, size_t);
	if (c == 'u' || c == 'd' || c == 'i')
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

char *pull_sizetp(t_print *form, va_list ap)
{
	size_t		*arg;

	arg = va_arg(ap, size_t *);
	*arg = ft_strlen(form->result);
	return (ft_strdup(""));
}

char	*length_z(t_print *form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_sizet(form, ap));
	if (c == 'n')
		return (pull_sizetp(form, ap));
	return (length_none(form, ap, c));
}
