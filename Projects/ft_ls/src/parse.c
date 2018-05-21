/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:07:52 by bchan             #+#    #+#             */
/*   Updated: 2018/05/21 12:34:33 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_error(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-AR@acelortu1] [file ...]", 2);
	exit(EXIT_FAILURE);
}

t_ls	*parse_flags(char **argv)
{
	int		i;
	int		j;
	t_ls	*ls;

	i = 0;
	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->flags = ft_strnew(0);
	while (argv[++i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 'l' && argv[i][j] != 'R' && argv[i][j] != 'a' &&
				argv[i][j] != 'r' && argv[i][j] != 't' && argv[i][j] != '@' &&
				argv[i][j] != 'e' && argv[i][j] != '1' && argv[i][j] != 'A' &&
				argv[i][j] != 'c' && argv[i][j] != 'u' && argv[i][j] != 'o')
			{
				flag_error(argv[i][j]);
			}
			ft_strpchar(&(ls->flags), argv[i][j++]);
		}
	}
	return (ls);
}

void	parse_args(int argc, char **argv, t_ls *ls)
{
	int	i;

	i = 1;
	ls->num_dir = 0;
	ls->num_files = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			i++;
		else
			break ;
	}
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
