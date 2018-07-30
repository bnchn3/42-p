/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:48:18 by bchan             #+#    #+#             */
/*   Updated: 2018/03/02 14:57:32 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hex_prep(char *result)
{
	char	*temp;
	int		i;

	i = 0;
	temp = &result[ft_strlen(result) - 4];
	while ((temp - &result[i]) % 4 != 0)
	{
		result = ft_insert_char(result, '0', i);
		temp = &result[ft_strlen(result) - 4];
	}
	return (result);
}

char	hex(int n)
{
	char	key[6];
	int		i;
	char	c;

	i = 0;
	c = 'a';
	while (i < 6)
		key[i++] = c++;
	n -= 10;
	return (key[n]);
}

char	to_hex(char *result)
{
	int i;

	i = 0;
	if (result[0] == '1')
		i += 8;
	if (result[1] == '1')
		i += 4;
	if (result[2] == '1')
		i += 2;
	if (result[3] == '1')
		i += 1;
	if (i >= 10)
		return (hex(i));
	return (i + '0');
}

char	*bin_to_hex(char *result)
{
	char	*temp;
	char	*save;
	int		i;

	i = 0;
	result = hex_prep(result);
	temp = &result[ft_strlen(result) - 4];
	save = ft_strdup("");
	while (temp != &result[i])
	{
		ft_strpchar(&save, to_hex(&result[i]));
		i += 4;
	}
	ft_strpstr(&save, temp);
	return (save);
}

char	*hex_float_convert(char *result, int i)
{
	char	*temp;
	char	*save;

	result = sci_convert(result, i * 4);
	temp = ft_strchr(result, 'e');
	*temp = 'p';
	temp = ft_strdup("");
	if (*result == '-')
		ft_strpchar(&temp, '-');
	if (*result == 0)
		ft_strpstr(&temp, "0x0");
	else
		ft_strpstr(&temp, "0x1");
	ft_strpchar(&temp, '.');
	ft_strpstr(&temp, (save = bin_to_hex(ft_strchr(result, '.') + 1)));
	ft_strdel(&save);
	ft_strdel(&result);
	return (temp);
}
