/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:44:44 by bchan             #+#    #+#             */
/*   Updated: 2017/10/31 17:21:16 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_baselen(char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		ft_baseinvalid(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_baselen(base) < 1)
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

void	ft_baseconvert(long long nbr, int len, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_baseconvert(-nbr, len, base);
	}
	else if (nbr >= len)
	{
		ft_baseconvert(nbr / len, len, base);
		ft_putchar(base[nbr % len]);
	}
	else
		ft_putchar(base[nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long long	nbr2;

	len = ft_baselen(base);
	if (ft_baseinvalid(base) == 0)
		ft_putchar('\0');
	else
	{
		nbr2 = (long long)nbr;
		ft_baseconvert(nbr2, len, base);
	}
}
