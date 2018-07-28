/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:23:28 by bchan             #+#    #+#             */
/*   Updated: 2018/02/26 14:15:52 by bchan            ###   ########.fr       */
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
	while ((result[i] <= '0' || result[i] > '9') && result[i])
		i++;
	while (count > 0 && result[i])
		if (ft_isdigit(result[i++]))
			count--;
	round_up(result, i);
	if (ft_strchr(&result[i], '.'))
	{
		while (result[i] != '.')
			result[i++] = '0';
	}
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
	if (!ft_strchr(temp, '.'))
		ft_strpchar(&temp, '.');
	if (form->precision == -1)
		temp = sci_convert(temp, 5);
	else
		temp = sci_convert(temp, form->precision - 1);
	if (ft_atoi(&temp[ft_strlen(temp) - 3]) < -4 || (ft_atoi(&temp[
		ft_strlen(temp) - 3]) >= form->precision && form->precision >= 0) ||
		(ft_atoi(&temp[ft_strlen(temp) - 3]) >= 6 && form->precision == -1))
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

char	*print_zero(char *result, int n)
{
	truncate_dec(result, n);
	ft_strpstr(&result, "e+00");
	return (result);
}

void	round_up(char *result, int i)
{
	if (result[i] >= '5' && result[i] <= '9')
		if (ft_isdigit(result[i - 1]))
		{
			if (result[i - 1] < '9')
				result[i - 1] += 1;
			else
			{
				result[--i] = '0';
				while (result != &result[i])
				{
					if (result[i - 1] < '9' && result[i - 1] >= '0')
					{
						result[i - 1] += 1;
						break ;
					}
					result[--i] = '0';
					if (result[i - 1] == '.')
						i--;
				}
			}
		}
}
