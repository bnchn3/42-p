/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:52:04 by bchan             #+#    #+#             */
/*   Updated: 2017/11/10 14:52:50 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (argc < 2)
		write(2, "File name missing.\n", 20);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 21);
	else
	{
		fd = open(argv[1], O_RDWR);
		if (fd != -1)
		{
			while ((ret = read(fd, buf, BUF_SIZE)))
				write(1, buf, BUF_SIZE);
		}
		close(fd);
	}
	return (0);
}
