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

	i = 0;
	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->flags = ft_strnew(0);
	while (argv[++i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 'l' && argv[i][j] != 'R' && argv[i][j] != 'a' &&
				argv[i][j] != 'r' && argv[i][j] != 't')
			{
				ft_putstr_fd("ft_ls: illegal option -- ", 2);
				ft_putchar_fd(argv[i][j], 2);
				ft_putchar_fd('\n', 2);
				ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
				exit(EXIT_FAILURE);
			}
			ft_strpchar(&(ls->flags), argv[i][j++]);
		}
	}
	return (ls);
}

int	is_file(char *str)
{
	struct stat	*buf;
	int		result;

	buf = (struct stat *)malloc(sizeof(struct stat));
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

void	swap_str(char *s1, char *s2);
{
	char *temp;

	temp = ft_strdup(s1);
	ft_strdel(&s1);
	s1 = ft_strdup(s2);
	ft_strdel(&s2);
	s2 = ft_strdup(temp);
}

void 	alpha_sort(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) > 0)
			{
				swap_str(str[i], str[j]);
				i = 0;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	reverse(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i + 1] != NULL)
		i++;
	j = 0;
	while (j < i)
		swap_str(str[j++], str[i--]);
}

time_t	get_time(char *str)
{
	time_t t;
	struct stat		*buf;

	buf = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(str, buf) == 0)
		t = buf->st_mtimespec->tv_sec;
	else
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	ft_memdel((void **)&buf);
	return (t);
}

void	sort_time(char **str)
{
	time_t	time1;
	time_t	time2;
	int i;
	int j;

	i = -1;
	while (str[++i])
	{
		j = i;
		time1 = get_time(str[i]);
		while (str[++j])
		{
			time2 = get_time(str[j]);
			if (time1 < time2 || (time1 == time2 && ft_strcmp(str[i], str[j]) > 0))
			{
				swap_str(str[i], str[j]);
				i = 0;
				break ;
			}
		}
	}
}

void	sort_files(t_ls *ls)
{
	if (ft_strchr(ls->flags, 'r') && ft_strchr(ls->flags, 't'))
	{
		sort_time(ls->files);
		reverse(ls->files);
	}
	else if (ft_strchr(ls->flags, 'r'))
		reverse(ls->files);
	else if (ft_strchr(ls->flags, 't'))
		sort_time(ls->files);
}

void	print_files_long(t_ls *ls)
{
	struct stat *buf;
	int		i;

	i = 0;
	while(i < ls->num_files)
	{
		if (lstat(ls->num_files[i], buf) == 0)
		{
			ft_putstr(get_mode(buf));
			ft_putstr(get_links(buf));
			ft_putstr(get_uid(buf));
			ft_putstr(get_gid(buf));
			ft_putstr(get_size(buf));
			ft_putstr(get_time_long(buf));
			ft_putendl(ls->num_files[i]);
		}
		else
		{
			perror("stat");
			exit(EXIT_FAILURE);
		}
		ft_memdel((void **)&buf);
	}
}

void	print_files(t_ls *ls)
{
	int	i;

	alpha_sort(ls->files);
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
