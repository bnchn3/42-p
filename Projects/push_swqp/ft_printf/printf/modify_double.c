/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:13:15 by bchan             #+#    #+#             */
/*   Updated: 2018/02/23 18:25:23 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	truncate_dec(char *result, int n)
{
	int	i;

	i = 0;
	while (result[i] && result[i] != '.')
		i++;
	while (n-- >= 0)
		i++;
	round_up(result, i);
	result[i] = '\0';
}

char	*add_exp(char *result, int count)
{
	char *temp;

	if (count >= 0)
	{
		ft_strpchar(&result, '+');
		if (count < 10)
			ft_strpchar(&result, '0');
		temp = ft_itoa(count);
		ft_strpstr(&result, temp);
	}
	else
	{
		ft_strpchar(&result, '-');
		if (count > -10)
			ft_strpchar(&result, '0');
		temp = ft_itoa(count * -1);
		ft_strpstr(&result, temp);
	}
	ft_strdel(&temp);
	return (result);
}

int		is_zero(char *result)
{
	int i;

	i = 0;
	while (result[i])
	{
		if (result[i] != '.' && result[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*sci_convert(char *str, int n)
{
	char	*temp;
	int		count;

	temp = ft_strchr(str, '.');
	count = 0;
	if (is_zero(str))
		return (print_zero(str, n));
	while (temp - str >= 3 || (*str != '-' && temp - str >= 2))
	{
		ft_swap(temp, temp - 1);
		count++;
		temp--;
	}
	while ((*str == '0' || (*str == '-' && *(str + 1) == '0')) && *temp)
	{
		ft_swap(temp, temp + 1);
		ft_memmove(temp - 1, temp, ft_strlen(temp) + 1);
		count--;
	}
	truncate_dec(str, n);
	ft_strpchar(&str, 'e');
	str = add_exp(str, count);
	return (str);
}

char	*modify_double(t_print *form, char *result)
{
	int		i;
	char	*temp;

	if (form->precision == -1)
		i = 6;
	else
		i = form->precision;
	if (form->spec == 'f' || form->spec == 'F')
		truncate_dec(result, i);
	else if (form->spec == 'e' || form->spec == 'E')
		result = sci_convert(result, i);
	else if (form->spec == 'g' || form->spec == 'G')
		result = find_shortest(form, result);
	else if (form->spec == 'a' || form->spec == 'A')
		result = hex_float_convert(result, i);
	if (form->spec == 'F' || form->spec == 'E' || form->spec == 'G' ||
			form->spec == 'A')
		ft_capitalize(result);
	if (!(ft_strchr(form->flags, '#')) && form->precision == 0 && form->spec
			!= 'g' && form->spec != 'G')
	{
		temp = ft_strchr(result, '.');
		ft_memmove(temp, temp + 1, ft_strlen(temp));
	}
	return (result);
}
