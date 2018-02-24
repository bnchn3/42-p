/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:23:28 by bchan             #+#    #+#             */
/*   Updated: 2018/02/23 18:25:00 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	sig_digit(t_print *form, char *result)
{
	int	i;
	int	count;

	i = 0;
	if (form->precision > 0)
		count = form->precision;
	else if (form->precision == 0)
		count = 1;
	else
		count = 6;
	while (result[i] <= '0' || result[i] > '9')
		i++;
	while (count > 0 && result[i])
		if (ft_isdigit(result[i++]))
			count--;
	result[i] = '\0';
}

void	trailing_zeroes(t_print *form, char *result)
{
	int i;

	i = ft_strlen(result) - 1;
	while ((result[i] == '0' || result[i] == '.') && ft_strchr(result, '.')
			&& !(ft_strchr(form->flags, '#')))
	{
		if (result[i] == '.')
		{
			result[i] = '\0';
			break ;
		}
		result[i--] = '\0';
	}
}

char	*find_shortest(t_print *form, char *result)
{
	char	*temp;

	sig_digit(form, result);
	trailing_zeroes(form, result);
	temp = ft_strdup(result);
	temp = sci_convert(temp, form->precision);
	if (ft_atoi(&temp[ft_strlen(temp) - 3]) < -4 ||
		(ft_atoi(&temp[ft_strlen(temp) - 3]) >= form->precision &&
		form->precision >= 0))
	{
		ft_strdel(&result);
		result = temp;
		temp = ft_strchr(result, '.');
		if (temp && !(ft_atoi(temp + 1)))
			ft_memmove(temp, temp + 1, ft_strlen(temp));
	}
	else
		ft_strdel(&temp);
	return (result);
}
