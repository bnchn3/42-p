/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pads.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:16:35 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:16:37 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	reset_pads(t_ls *ls)
{
	ls->link_pad = 0;
	ls->user_pad = 0;
	ls->group_pad = 0;
	ls->size_pad = 0;
}

int		get_col_pad(char **contents)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (contents[i])
	{
		if ((int)ft_strlen(contents[i]) > j)
			j = ft_strlen(contents[i]);
		i++;
	}
	return (j);
}

void	get_user_pad(t_ls *ls, struct stat *buf)
{
	struct passwd *p;

	p = getpwuid(buf->st_uid);
	if (p)
	{
		if (ft_strlen(p->pw_name) > (size_t)ls->user_pad)
			ls->user_pad = ft_strlen(p->pw_name);
	}
	else
	{
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
}

void	get_group_pad(t_ls *ls, struct stat *buf)
{
	struct group *g;

	g = getgrgid(buf->st_gid);
	if (g)
	{
		if (ft_strlen(g->gr_name) > (size_t)ls->group_pad)
			ls->group_pad = ft_strlen(g->gr_name);
	}
	else
	{
		perror("getgrgid");
		exit(EXIT_FAILURE);
	}
}

void	get_pads(t_ls *ls, char **str, char *path, struct stat *buf)
{
	int		i;
	char	*temp;

	reset_pads(ls);
	i = 0;
	while (str[i])
	{
		temp = ft_strjoin(path, str[i++]);
		if (lstat(temp, buf) == 0)
		{
			if (ft_intlen(buf->st_nlink) > (size_t)ls->link_pad)
				ls->link_pad = ft_intlen(buf->st_nlink);
			if (ft_intlen(buf->st_size) > (size_t)ls->size_pad)
				ls->size_pad = ft_intlen(buf->st_size);
			get_user_pad(ls, buf);
			get_group_pad(ls, buf);
		}
		else
			perror(temp);
		ft_strdel(&temp);
	}
}
