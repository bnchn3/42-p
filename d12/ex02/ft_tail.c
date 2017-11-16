/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:53:56 by bchan             #+#    #+#             */
/*   Updated: 2017/11/09 18:44:24 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void    ft_puterr(char *str)
{
	int     i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int     ft_strcmp(char *s1, char *s2)
{
	int     i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

int     ft_atoi(char *str)
{
	int i;
	int nbr;
	int isnegative;

	nbr = 0;
	isnegative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		isnegative = 1;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (isnegative == 1)
		return (-nbr);
	else
		return (nbr);
}

void    ft_display_file(char *str, int byte, char buf[], char c)
{
	int     fd;
	int     ret;
	int		i;

	fd = open(str, O_RDWR);
	i = 0;
	if (fd != -1)
	{
		if (c == '+')
		{
			while (i < byte)
			{
				read(fd, buf, 1);
				i++;
			}
			while ((ret = read(fd, buf, 1)))
				write(1, buf, 1);
		}
	}
	else
	{
		ft_puterr("ft_tail: ");
		ft_puterr(str);
		ft_puterr(": No such file or directory\n");
	}
	close(fd);
}

int     main(int argc, char **argv)
{
	int     i;
	char    buf[2];
	int		byte;
	char	c;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
		{
			if (argv[i + 1][0] == '+')
				c = '+';
			byte = ft_atoi(argv[i + 1]);
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_display_file(argv[i], byte, buf, c);
		i++;
	}
	return (0);
}
