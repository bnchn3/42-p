/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:04:04 by bchan             #+#    #+#             */
/*   Updated: 2018/02/16 16:22:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*force_dec(char *result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		if (result[i] == '.')
			return (result);
		i++;
	}
	ft_strpstr(&result, ".");
	return (result);
}

char	*apply_pound(char c, char *result)
{
	char	*tmp;

	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'f' || c == 'F'
		|| c == 'g' || c == 'G')
		return (force_dec(result));
	if (c == 'd' || c == 'i' || c == 'D')
		return (result);
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
	if (form->spec == 'd' || form->spec == 'i' || form->spec == 'D')
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
