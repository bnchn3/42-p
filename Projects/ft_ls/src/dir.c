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

void	print_dir_long(char **contents, char *path, char **sub, t_ls *ls)
{
	int			i;
	int			j;
	struct stat	*buf;
	char		*temp;

	i = -1;
	j = 0;
	buf = (struct stat *)malloc(sizeof(struct stat));
	get_pads(ls, contents, path, buf);
	get_dir_size(contents, path, buf);
	while (contents[++i])
	{
		temp = ft_strjoin(path, contents[i]);
		if (lstat(temp, buf) == 0)
		{
			if (S_ISDIR(buf->st_mode))
				sub[j++] = ft_strdup(temp);
			get_mode(temp, buf, ls);
			get_name(temp, contents[i], buf, ls);
		}
		else
			perror(temp);
		ft_strdel(&temp);
	}
	ft_memdel((void **)&buf);
}

void	print_dir(char **contents, char *path, char **sub)
{
	int			i;
	int			j;
	struct stat	*buf;
	char		*temp;

	i = 0;
	j = 0;
	buf = (struct stat *)malloc(sizeof(struct stat));
	while (contents[i])
	{
		temp = ft_strjoin(path, contents[i]);
		if (lstat(temp, buf) == 0)
		{
			if (S_ISDIR(buf->st_mode))
				sub[j++] = ft_strdup(temp);
		}
		else
			perror(temp);
		ft_putendl(contents[i++]);
		ft_strdel(&temp);
	}
	ft_memdel((void **)&buf);
}

void	print_rec(t_ls *ls, char **sub)
{
	int		i;

	i = 0;
	while (sub[i])
	{
		ls->first++;
		list_dir(&sub[i], ls);
		i++;
	}
}

void	list_dir(char **path, t_ls *ls)
{
	char	**contents;
	char	**sub;

	contents = read_dir(*path, ls);
	sub = copy_2d(contents);
	if (ls->first++ > 0)
	{
		if (ls->first > 2)
			ft_putchar('\n');
		ft_putstr(*path);
		ft_putendl(":");
	}
	ft_strpchar(path, '/');
	alpha_sort(contents);
	if (ft_strchr(ls->flags, 'r') || ft_strchr(ls->flags, 't'))
		sort_files(contents, ls);
	if (ft_strrchr(ls->flags, 'l') > ft_strrchr(ls->flags, '1'))
		print_dir_long(contents, *path, sub, ls);
	else
		print_dir(contents, *path, sub);
	char_del(contents);
	if (ft_strchr(ls->flags, 'R'))
		print_rec(ls, sub);
	char_del(sub);
}
