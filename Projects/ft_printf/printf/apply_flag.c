/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:04:04 by bchan             #+#    #+#             */
/*   Updated: 2018/02/19 13:18:25 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*apply_pound(char c, char *result)
{
	char	*tmp;

	tmp = NULL;
	if ((c == 'o' || c == 'O') && result[0] != '0')
		tmp = ft_strjoin("0", result);
	if (c == 'x' && result[0] != '0')
		tmp = ft_strjoin("0x", result);
	if (c == 'X' && result[0] != '0')
		tmp = ft_strjoin("0X", result);
	if (tmp)
	{
		ft_strdel(&result);
		return (ft_strdup(tmp));
	}
	return (result);
}

char	*apply_flag(t_print *form, char *result)
{
	char *temp;

	temp = NULL;
	if (number_spec2(form->spec))
	{
		if (ft_strchr(form->flags, '+') && result[0] != '-')
			temp = ft_strjoin("+", result);
		else if (ft_strchr(form->flags, ' ') && result[0] != '-')
			temp = ft_strjoin(" ", result);
	}
	if (ft_strchr(form->flags, '#') && number_spec(form->spec))
		temp = apply_pound(form->spec, result);
	if (temp && temp != result)
	{
		ft_strdel(&result);
		result = temp;
	}
	return (result);
}
