/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:34:09 by bchan             #+#    #+#             */
/*   Updated: 2018/03/02 11:47:28 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	round_num(long double n)
{
	long double	save;
	int			i;

	save = n;
	i = 0;
	if (n < 1)
		return (0);
	while (ft_power(10L, i) <= n)
		i++;
	i--;
	while (i >= 0)
	{
		while (save - ft_power(10L, i) >= 0)
			save -= ft_power(10L, i);
		i--;
	}
	return (n - save);
}

static long double	get_decimal(long double n, char **result)
{
	int count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (count < 18)
	{
		n *= 10;
		if (n > -1 && n < 1)
			ft_strpchar(result, '0');
		count++;
	}
	return (n);
}

static char			*get_number(long double n, char *temp)
{
	int			count;
	int			i;
	long double	save;

	i = 0;
	if (n < 1 && n > -1)
		return (ft_strcpy(temp, "0"));
	if (n < 0)
		n *= -1.0L;
	save = n;
	while (ft_power(10L, i) <= n)
		i++;
	while (--i >= 0)
	{
		count = 0;
		while (save - ft_power(10L, i) >= 0)
		{
			save -= ft_power(10L, i);
			count++;
		}
		ft_strpchar(&temp, count + '0');
	}
	return (temp);
}

char				*ft_dtoa(long double n, int i)
{
	char		*result;
	char		*temp;
	long double	save;

	result = ft_strdup("");
	if (n < 0)
		ft_strpchar(&result, '-');
	temp = get_number(n, ft_strdup(""));
	ft_strpstr(&result, temp);
	if (n < 0)
		n *= -1;
	save = round_num(n);
	ft_strpchar(&result, '.');
	if (n - save != 0)
	{
		save = get_decimal(n - save, &result);
		temp = get_number(save, ft_strdup(""));
		ft_strpstr(&result, temp);
	}
	else
		while (i++ < 19)
			ft_strpchar(&result, '0');
	ft_strdel(&temp);
	return (result);
}
