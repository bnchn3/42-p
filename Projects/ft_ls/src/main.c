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

t_ls	*parse_flags(int argc, char **argv, t_ls *ls)
{
	int i;
	int j;

	i = 1;
	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->flags = ft_strnew(0);
	while (argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 'l' && argv[i][j] != 'R' && argv[i][j] != 'a' &&
				argv[i][j] != 'r' && argv[i][j] != 't')
			{
				ft_putstr_fd("ft_ls: unknown option -- ", 2);
				ft_putchar_fd(argv[i][j], 2);
				ft_putchar_fd('\n', 2);
				exit(EXIT_FAILURE);
			}
			ft_strpchar(&(ls->flags), argv[i][j++]);
		}
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

void	parse_args(int argc, char **argv, t_ls *ls)
{
	int	i;

	i = 1;
	ls->num_dir = 0;
	ls->num_files = 0;
	while (i < argc)
		if (argv[i][0] == '-')
			i++;
	ls->dirs = (char **)malloc(sizeof(char *) * (argc - i + 1));
	ls->files = (char **)malloc(sizeof(char *) * (argc - i + 1));
	while (i < argc)
	{
		if (is_file(argv[i]))
			ls->files[ls->num_files++] = ft_strdup(argv[i]);
		else
		 	ls->dirs[ls->num_dir++] = ft_strdup(argv[i]);
		i++;
	}
	ls->files[ls->num_files] = NULL;
	ls->dirs[ls->num_dir] = NULL;
}

void	sort_files(t_ls *ls)
{
	
}

void	print_files(t_ls *ls)
{
	int	i;

	if (ft_strchr(ls->flags, 'r') || ft_strchr(ls->flags, 't')
		sort_files(ls);
	if (ft_strchr(ls->flags, 'l'))
		print_files_long(ls);
	else
	{
		i = 0;
		while (i < ls->num_files)
			ft_putendl(ls->files[i]);
		i++;
	}
	if (ls->num_dir > 0)
		ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	t_ls	*ls;

	ls = parse_flags(argc, argv, ls);
	parse_args(argc, argv, ls);
	if (ls->num_files > 0)
		print_files(ls);
	return (0);
}
