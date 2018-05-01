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
	ls->args = (t_list **)malloc(sizeof(t_list *));
	*(ls->args) = ft_lstnew(NULL, 0);
	ls->num = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_strpchar(&(ls->flags), argv[i][1]);
		else
			break ;
		i++;
	}
	while (i < argc)
	{
		ft_lstadd(ls->args, ft_lstnew(argv[i], ft_strlen(argv[i])));
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

	if (argc == 1)
		listdir(".");
	else
	{
		ls = parse_flags(argc, argv);
		while (i < argc)
		{
			if (is_file(argv[i]))
				ft_putstr(argv[i]);
			else
				listdir(argv[i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
