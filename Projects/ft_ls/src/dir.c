/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:29:06 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:37:27 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_sub(char **contents, char *path, char **sub)
{
	int			i;
	int			j;
	struct stat	*buf;
	char		*temp;

	i = -1;
	j = 0;
	buf = (struct stat *)malloc(sizeof(struct stat));
	while (contents[++i])
	{
		if (ft_strcmp(contents[i], ".") != 0 &&
			ft_strcmp(contents[i], "..") != 0)
			temp = ft_strjoin(path, contents[i]);
		else
			continue ;
		if (lstat(temp, buf) == 0)
		{
			if (S_ISDIR(buf->st_mode))
				sub[j++] = ft_strdup(temp);
		}
		else
			perror(temp);
		ft_strdel(&temp);
	}
	ft_memdel((void **)&buf);
}

void	print_dir_long(char **contents, char *path, char **sub, t_ls *ls)
{
	int			i;
	struct stat	*buf;
	char		*temp;

	i = -1;
	get_sub(contents, path, sub);
	buf = (struct stat *)malloc(sizeof(struct stat));
	get_pads(ls, contents, path, buf);
	get_dir_size(contents, path, buf);
	while (contents[++i])
	{
		temp = ft_strjoin(path, contents[i]);
		if (lstat(temp, buf) == 0)
		{
			get_mode(temp, buf, ls);
			get_name(temp, contents[i], buf, ls);
		}
		else
			perror(temp);
		ft_strdel(&temp);
	}
	ft_memdel((void **)&buf);
}

void	print_dir(char **contents, char *path, char **sub, t_ls *ls)
{
	int			i;

	get_sub(contents, path, sub);
	if (ft_strchr(ls->flags, '1'))
	{
		i = 0;
		while (contents[i])
			ft_putendl(contents[i++]);
	}
	else
		get_col(contents);
}

void	print_rec(t_ls *ls, char **sub)
{
	int		i;

	i = 0;
	if (sub)
	{
		while (sub[i])
		{
			ls->first++;
			list_dir(&sub[i], ls, NULL);
			i++;
		}
	}
}

void	list_dir(char **path, t_ls *ls, char **sub)
{
	char	**contents;

	if ((contents = read_dir(*path, ls, 0)))
	{
		sub = copy_2d(contents);
		if (ls->first++ > 0)
		{
			if (ls->first > 2)
				ft_putchar('\n');
			ft_putstr(*path);
			ft_putendl(":");
		}
		if (ft_strcmp(*path, "/"))
			ft_strpchar(path, '/');
		sort_files(contents, *path, ls);
		if (ft_strrchr(ls->flags, 'l') > ft_strrchr(ls->flags, '1') ||
			ft_strchr(ls->flags, 'o'))
			print_dir_long(contents, *path, sub, ls);
		else
			print_dir(contents, *path, sub, ls);
		char_del(contents);
	}
	if (ft_strchr(ls->flags, 'R'))
		print_rec(ls, sub);
	char_del(sub);
}
