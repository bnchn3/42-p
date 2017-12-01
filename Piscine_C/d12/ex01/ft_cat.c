/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:02:58 by bchan             #+#    #+#             */
/*   Updated: 2017/11/09 18:32:58 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1

void	ft_puterr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_display_file(char *str)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(str, O_RDWR);
	if (fd != -1)
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
			write(1, buf, BUF_SIZE);
	}
	else
	{
		ft_puterr("ft_cat: ");
		ft_puterr(str);
		ft_puterr(": No such file or directory\n");
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int		i;
	char	buf[BUF_SIZE + 1];

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' || argc < 2)
		{
			while (read(0, buf, BUF_SIZE))
				write(1, buf, BUF_SIZE);
		}
		else
			ft_display_file(argv[i]);
		i++;
	}
	return (0);
}
