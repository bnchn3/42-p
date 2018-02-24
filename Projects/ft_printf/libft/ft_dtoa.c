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

char				*ft_dtoa(long double n, int i)
{
	char		*result;
	char		*temp;
	long double	save;

	result = ft_strdup("");
	if (n > -1 && n < 0)
		ft_strpchar(&result, '-');
	temp = ft_max_itoa((long long)n);
	ft_strpstr(&result, temp);
	if (n < 0)
		n *= -1;
	save = round_num(n);
	ft_strpchar(&result, '.');
	if (n - save != 0)
	{
		save = get_decimal(n - save, &result);
		temp = ft_max_itoa((long long)save);
		ft_strpstr(&result, temp);
	}
	else
		while (i++ < 19)
			ft_strpchar(&result, '0');
	ft_strdel(&temp);
	return (result);
}
