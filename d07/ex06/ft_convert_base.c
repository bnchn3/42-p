/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:39:17 by bchan             #+#    #+#             */
/*   Updated: 2017/11/02 13:13:06 by bchan            ###   ########.fr       */
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

int		ft_baselen(char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		ft_baseconvert(char *str, char *base, int len, int i)
{
	int		j;
	int		strlen;
	int		nbr;

	nbr = 0;
	strlen = 0;
	while (str[strlen] != '\0')
		strlen++;
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		len;
	int		isnegative;
	int		strlen;
	char	*result;

	i = 0;
	len = ft_baselen(base_from);
	strlen = 0;
	while (nbr[strlen] != '\0')
		strlen++;
	result = (char *)malloc((strlen - 1) * 
