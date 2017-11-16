/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:05:35 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 13:30:20 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int		ft_compare(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		while ((s1[i] == ' ' || s1[i] == '\t' || s1[i] == '\n') && s1[i])
			i++;
		if (s1[i])
		{
			j = 0;
			while (s2[j])
			{
				if (s1[i] != s2[j])
					return (0);
				j++;
				i++;
			}
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_lowercase(argv[i]);
		if (ft_compare(argv[i], "bauer") == 1 || ft_compare(argv[i],
				"president") == 1 || ft_compare(argv[i], "attack") == 1)
		{
			ft_putstr("Alert!!!\n");
		}
		i++;
	}
	return (0);
}
