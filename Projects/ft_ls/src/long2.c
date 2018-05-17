/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:23:21 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:36:49 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_size(struct stat *buf, t_ls *ls)
{
	int	pad;

	pad = ls->size_pad - ft_intlen(buf->st_size);
	while (pad)
	{
		ft_putchar(' ');
		pad--;
	}
	ft_putnbr(buf->st_size);
	ft_putchar(' ');
	get_time_long(buf);
}

void	get_group(struct stat *buf, t_ls *ls)
{
	int				pad;
	struct group	*g;

	g = getgrgid(buf->st_gid);
	if (g)
	{
		pad = ls->group_pad - ft_strlen(g->gr_name);
		while (pad)
		{
			ft_putchar(' ');
			pad--;
		}
		ft_putstr(g->gr_name);
		ft_putstr("  ");
	}
	else
	{
		perror("getgrgid");
		exit(EXIT_FAILURE);
	}
	get_size(buf, ls);
}

void	get_user(struct stat *buf, t_ls *ls)
{
	int				pad;
	struct passwd	*p;

	p = getpwuid(buf->st_uid);
	if (p)
	{
		pad = ls->user_pad - ft_strlen(p->pw_name);
		while (pad)
		{
			ft_putchar(' ');
			pad--;
		}
		ft_putstr(p->pw_name);
		ft_putstr("  ");
	}
	else
	{
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
	get_group(buf, ls);
}

void	get_links(struct stat *buf, t_ls *ls)
{
	int pad;

	pad = ls->link_pad - ft_intlen(buf->st_nlink);
	while (pad)
	{
		ft_putchar(' ');
		pad--;
	}
	ft_putnbr(buf->st_nlink);
	ft_putchar(' ');
	get_user(buf, ls);
}
