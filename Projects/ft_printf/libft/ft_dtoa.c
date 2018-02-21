/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:34:09 by bchan             #+#    #+#             */
/*   Updated: 2018/02/21 13:49:04 by bchan            ###   ########.fr       */
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
	while (ft_power(10, i) <= n)
		i++;
	i--;
	while (i >= 0)
	{
		while (save - ft_power(10, i) >= 0)
			save -= ft_power(10, i);
		i--;
	}
	return (n - save);
}

static long double	mod_double(long double n, long double i)
{
	if (n < 0)
	{
		if (i > 0)
			i *= -1;
		while (n - i <= i)
			n -= i;
	}
	if (n > 0)
	{
		if (i < 0)
			i *= -1;
		while (n - i >= i)
			n -= i;
	}
	return (n);
}

static long double	get_decimal(long double n)
{
	int count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (count < 19)
	{
		n *= 10;
		count++;
	}
	return (round_num(n));
}

static char			*get_number(long double save, char *result)
{
	int isneg;

	isneg = 0;
	if (save < 0)
	{
		isneg = 1;
		save *= -1;
	}
	while (save >= 10)
	{
		ft_strpchar(&result, (int)(mod_double(save, 10) + '0'));
		save /= 10;
	}
	ft_strpchar(&result, (int)save + '0');
	if (isneg == 1)
		ft_strpchar(&result, '-');
	result = ft_strrev(result);
	return (result);
}

char				*ft_dtoa(long double n, int i)
{
	char		*result;
	char		*temp;
	long double	save;

	result = ft_strdup("");
	if (n < -1 && n < 0)
		ft_strpchar(&result, '-');
	temp = ft_max_itoa((long long)n);
	ft_strpstr(&result, temp);
	if (n < 0)
		n *= -1;
	save = round_num(n);
	ft_strpchar(&result, '.');
	if (n - save != 0)
	{
		save = get_decimal(n - save);
		temp = ft_max_itoa((long long)save);
		ft_strpstr(&result, temp);
	}
	else
		while (i++ < 19)
			ft_strpchar(&result, '0');
	ft_strdel(&temp);
	return (result);
}
