/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:45:13 by bchan             #+#    #+#             */
/*   Updated: 2018/02/16 16:15:42 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_print		*new_form(size_t printed)
{
	t_print	*form;

	form = (t_print *)malloc(sizeof(t_print));
	form->flags = ft_strdup("");
	form->width = 0;
	form->precision = -1;
	form->spec = 0;
	form->printed = printed;
	form->null = 0;
	return (form);
}

t_print		*get_form(const char *format, t_print *form, va_list ap)
{
	int	i;

	i = 0;
	while (format[i] == '+' || format[i] == '-' || format[i] == ' ' ||
			format[i] == '0' || format[i] == '#')
		ft_strpchar(&(form->flags), format[i++]);
	if (ft_atoi(&(format[i])) || format[i] == '*')
	{
		if (format[i] == '*')
			form->width = va_arg(ap, int);
		else
			form->width = ft_atoi(&(format[i]));
		while (ft_isdigit(format[i]) || format[i] == '*')
			i++;
	}
	if (format[i] == '.')
	{
		if (format[i + 1] == '*')
			form->precision = va_arg(ap, int);
		else
			form->precision = ft_atoi(&(format[i + 1]));
	}
	form->spec = get_spec(format);
	return (form);
}

void		form_del(t_print *form)
{
	if (form)
	{
		if (form->flags)
		{
			ft_strdel(&(form->flags));
			form->flags = NULL;
		}
		free(form);
		form = NULL;
	}
}
