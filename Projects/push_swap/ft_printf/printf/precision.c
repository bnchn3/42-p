/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:15:03 by bchan             #+#    #+#             */
/*   Updated: 2018/02/19 12:38:06 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*minimum_digits(char c, char *result, t_print *form)
{
	char	*save;

	save = find_save(c, result, form);
	if (ft_atoi(save) == 0 && form->precision == 0)
	{
		if (form->width)
			ft_memset(result, ' ', ft_strlen(result));
		else
			ft_memset(result, '\0', ft_strlen(result));
	}
	else if (find_digits(save) > form->precision)
		while (find_zeroes(save))
		{
			remove_zero(form, save, result);
			save = find_save(c, result, form);
		}
	else if (find_digits(save) + find_zeroes(save) > form->precision)
		while (find_digits(save) + find_zeroes(save) > form->precision)
		{
			remove_zero(form, save, result);
			save = find_save(c, result, form);
		}
	else
		result = add_zero(form, save, result);
	return (result);
}

char	*max_char(char *result, t_print *form, char *temp)
{
	char	*save;

	save = result;
	if (form->null == 1 && form->precision < 6)
	{
		ft_memset(result, '\0', ft_strlen(result));
		return (result);
	}
	while (ft_strncmp(temp, save, ft_strlen(temp)) != 0)
		save++;
	save[form->precision] = '\0';
	if (form->width && ft_strlen(result) < (size_t)form->width)
	{
		if (ft_strchr(form->flags, '-'))
			while (ft_strlen(result) < (size_t)form->width)
				ft_strpstr(&result, " ");
		else
			while (ft_strlen(result) < (size_t)form->width)
				result = ft_insert_char(result, ' ', 0);
	}
	return (result);
}

char	*apply_precision(char *temp, char *result, t_print *form)
{
	char	c;

	c = form->spec;
	if (ft_atoi(result) == 0 && form->precision == 0 && ft_strchr(form->flags,
			'#') && (form->spec == 'o' || form->spec == 'O'))
	{
		ft_strdel(&result);
		return (ft_strdup("0"));
	}
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'o'
		|| c == 'O' || c == 'x' || c == 'X')
		result = minimum_digits(c, result, form);
	else if (c == 's')
		result = max_char(result, form, temp);
	return (result);
}
