/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:08:16 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:09:51 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*add_lead(char *result, char *temp, int wid)
{
	char	*s;

	if (temp[0] == '0' && result[0] == '0' && result[1] == 'x')
	{
		s = ft_strdup(result);
		while (wid > 0)
		{
			s = ft_insert_char(s, '0', 2);
			wid--;
		}
	}
	else if (temp[0] == '0' && (result[0] == ' ' || result[0] == '+' ||
			result[0] == '-'))
	{
		s = ft_strdup(result);
		while (wid > 0)
		{
			s = ft_insert_char(s, '0', 1);
			wid--;
		}
	}
	else
		s = ft_strjoin(temp, result);
	return (s);
}

char	*apply_width(t_print *form, char *result)
{
	char	*temp;
	char	*save;

	if (form->width <= (int)ft_strlen(result))
		return (result);
	if (form->spec == 'c' && result[0] == 0)
		temp = ft_strnew_char(form->width - 1, ' ');
	else
		temp = ft_strnew_char(form->width - ft_strlen(result), ' ');
	save = NULL;
	if (ft_strchr(form->flags, '0') && (number_spec(form->spec)))
		temp = ft_memset(temp, '0', ft_strlen(temp));
	if (ft_strchr(form->flags, '-'))
	{
		temp = ft_memset(temp, ' ', ft_strlen(temp));
		save = ft_strjoin(result, temp);
	}
	else
		save = add_lead(result, temp, form->width - ft_strlen(result));
	free(result);
	free(temp);
	return (save);
}
