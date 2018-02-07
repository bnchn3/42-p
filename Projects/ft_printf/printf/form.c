/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:45:13 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:46:39 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_print	*new_form(void)
{
	t_print	*form;

	form = (t_print *)malloc(sizeof(t_print));
	form->flags = ft_strdup("");
	form->width = 0;
	form->precision = -1;
	form->spec = 0;
	return (form);
}

t_print	*get_form(const char *format, t_print *form)
{
	int	i;

	i = 1;
	while (format[i] == '+' || format[i] == '-' || format[i] == ' ' ||
			format[i] == '0' || format[i] == '#')
		ft_strpchar(&(form->flags), format[i++]);
	if (ft_atoi(&(format[i])))
	{
		form->width = ft_atoi(&(format[i]));
		while (ft_isdigit(format[i]))
			i++;
	}
	if (format[i] == '.')
		form->precision = ft_atoi(&(format[i + 1]));
	form->spec = get_spec(format);
	return (form);
}
