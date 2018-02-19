/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:28:42 by bchan             #+#    #+#             */
/*   Updated: 2018/02/16 16:20:52 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*modify_string(t_print *form, char *result)
{
	char	*temp;

	temp = ft_strdup(result);
	result = apply_flag(form, result);
	result = apply_width(form, result);
	if (form->precision >= 0)
		result = apply_precision(temp, result, form);
	if (ft_strchr(form->flags, ' ') && (form->spec == 'd' || form->spec == 'i' ||
			form->spec == 'D') && !(ft_strchr(form->flags, '+')) && ft_atoi(result)
			>= 0 && result[0] != ' ')
			result = ft_insert_char(result, ' ', 0);
	free(temp);
	return (result);
}

char	*check_length(const char *format, va_list ap, t_print *form)
{
	int	i;

	i = 0;
	while (!(check_spec(format[i])))
		i++;
	if (format[i - 1] == 'h')
	{
		if (format[i - 2] == 'h')
			return (length_hh(form, ap, format[i]));
		return (length_h(form, ap, format[i]));
	}
	if (format[i - 1] == 'l')
	{
		if (format[i - 2] == 'l')
			return (length_ll(form, ap, format[i]));
		return (length_l(form, ap, format[i]));
	}
	if (format[i - 1] == 'j')
		return (length_j(form, ap, format[i]));
	if (format[i - 1] == 'z')
		return (length_z(form, ap, format[i]));
	return (length_none(form, ap, format[i]));
}

size_t	print_arg(const char *format, va_list ap, size_t printed)
{
	char	*new;
	t_print	*form;
	size_t	result;

	form = new_form(printed);
	form = get_form(format, form, ap);
	new = check_length(format, ap, form);
	result = 0;
	ft_putstr(new);
	if (form->spec == 'c' && form->null == 1)
	{
		ft_putchar(0);
		result++;
	}
	result += ft_strlen(new);
	ft_strdel(&new);
	form_del(form);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			i;
	size_t			printed;

	i = 0;
	printed = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed += print_arg(&(format[++i]), ap, printed);
			while (!(check_spec(format[i++])))
				;
		}
		else
		{
			ft_putchar(format[i++]);
			printed++;
		}
	}
	va_end(ap);
	return (printed);
}
