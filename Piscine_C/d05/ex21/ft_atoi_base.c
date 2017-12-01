/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:12:41 by bchan             #+#    #+#             */
/*   Updated: 2017/10/31 16:20:30 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int base, int power)
{
	int result;

	result = base;
	if (power == 0)
		return (1);
	else
		result *= ft_power(base, power - 1);
	return (result);
}

int		ft_baseinvalid(char *base, int len)
{
	int		i;
	int		j;

	i = 0;
	if (len < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_strinvalid(char *str, char *base)
{
	int		i;
	int		j;
	int		isvalid;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		isvalid = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j] || str[i] == '+' || str[i] == '-')
				isvalid = 1;
			j++;
		}
		if (isvalid == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_baseconvert(char *str, char *base, int len, int i)
{
	int		j;
	int		strlen;
	int		nbr;

	j = i;
	nbr = 0;
	strlen = 0;
	while (str[j] != '\0')
	{
		strlen++;
		j++;
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
				nbr += j * ft_power(len, strlen - 1);
			j++;
		}
		i++;
		strlen--;
	}
	return (nbr);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		len;
	int		isnegative;

	i = 0;
	len = 0;
	isnegative = 1;
	while (base[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	if (ft_baseinvalid(base, len) == 0 || ft_strinvalid(str, base) == 0)
		return (0);
	if (str[i] == '-')
		isnegative = -1;
	while (str[i] == '+' || str[i] == '-')
		i++;
	return (isnegative * ft_baseconvert(str, base, len, i));
}
