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

t_ls	*parse_flags(int argc, char **argv)
{
	int i;
	t_ls	*ls;

	i = 1;
	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->flags = ft_strnew(0);
	ls->num = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_strpstr(&(ls->flags), &(argv[i][1]));
		else
			break ;
		i++;
	}
	ls->args = (char **)malloc(sizeof(char *) * (argc - i));
	while (i < argc)
	{
		ls->args[ls->num] = ft_strdup(argv[i]);
		ls->num++;
		i++;
	}
	return (ls);
}

int	is_file(char *str)
{
	struct stat	*buf;
	int		result;

	buf = (struct stat *)malloc(sizeof(stat));
	if (stat(str, buf) == 0)
	{
		if (buf->st_mode == S_IFDIR)
			result = 0;
		else
			result = 1;
	}
	else
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	ft_memdel((void **)&buf);
	return (result);
}

int	main(int argc, char **argv)
{
	t_ls	*ls;

	ls = parse_flags(argc, argv);
	return (0);
}
