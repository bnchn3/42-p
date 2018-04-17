/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:07:10 by bchan             #+#    #+#             */
/*   Updated: 2018/04/16 15:07:14 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*find_path(char *str)
{
	
}

int	is_file(char *str)
{
	stat	*buf;
	char	*path;
	int		result;

	path = find_path(str);
	buf = (stat *)malloc(sizeof(stat));
	if (stat(path, buf))
	{
		if (buf->st_mode == S_IFDIR)
			result = 0;
		else if (buf->st_mode == S_IFLNK)
			result = is_file_link(str);
		else
			result = 1;
	}
	else
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	ft_memdel(&buf);
	ft_strdel(&path);
	return (result);
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		listdir(".");
	else
	{
		while (i < argc)
		{
			if (is_file(argv[i]))
				ft_putstr(argv[i]);
			else
				listdir(argv[i]);
			i++;
		}
	}
	return (0);
}
