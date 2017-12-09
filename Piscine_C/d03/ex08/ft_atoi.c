/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:09:17 by bchan             #+#    #+#             */
/*   Updated: 2017/10/27 20:25:15 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_length(char *str);
int		ft_neg(char *str);

int		ft_convert(char *str, int i, int final)
{
	int		legend[10];
	int		n;

	n = 0;
	while (n < 10)
	{
		legend[n] = n;
		n++;
	}
	while (*str != '\0')
	{
		n = 0;
		while (n < 10)
		{
			if ((legend[n] + '0') == *str)
			{
				final += legend[n] * i;
				i /= 10;
			}
			n++;
		}
		str++;
	}
	return (final);
}

int		ft_atoi(char *str)
{
	int		length;
	int		final;
	int		mult;
	int		isnegative;

	mult = 1;
	isnegative = ft_neg(str);
	if (isnegative == -1)
		str++;
	final = 0;
	length = ft_length(str);
	while (length > 1)
	{
		mult *= 10;
		length--;
	}
	final = ft_convert(str, mult, final);
	return (final * isnegative);
}

int		ft_length(char *str)
{
	char	*len;
	int		length;

	len = str;
	length = 0;
	while (*len != '\0')
	{
		length++;
		len++;
	}
	return (length);
}

int		ft_neg(char *str)
{
	if (*str == '-')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
