/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:28:42 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:57:14 by bchan            ###   ########.fr       */
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

char	*print_arg(const char *format, va_list ap, char *result)
{
	char	*new;
	t_print	*form;

	if (format[1] == '%')
		return (ft_strdup("%"));
	form = new_form(result);
	form = get_form(format, form, ap);
	new = check_length(format, ap, form);
	form_del(form);
	return (new);
}

int		print_result(char *result)
{
	int	i;

	ft_putstr(result);
	i = ft_strlen(result);
	ft_strdel(&result);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*result;
	size_t			i;
	char			*temp;

	result = ft_strdup("");
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = print_arg(&(format[i++]), ap, result);
			ft_strpstr(&result, temp);
			ft_strdel(&temp);
			while (!(check_spec(format[i++])))
				if (format[i - 1] == '%')
					break ;
		}
		else
			ft_strpchar(&result, format[i++]);
	}
	i = print_result(result);
	va_end(ap);
	return (i);
}
