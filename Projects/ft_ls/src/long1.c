/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:19:52 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:39:51 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_ext_attr(char *path, struct stat *buf, t_ls *ls)
{
	acl_t	acl;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if ((acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		if (acl_valid(acl) == 0)
			ft_putchar('+');
		acl_free(acl);
	}
	else
		ft_putchar(' ');
	ft_putchar(' ');
	get_links(path, buf, ls);
}

void	get_other_per(char *path, struct stat *buf, t_ls *ls)
{
	if (buf->st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (buf->st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf->st_mode & S_IXOTH) && (buf->st_mode & S_ISVTX))
		ft_putchar('t');
	else if (buf->st_mode & S_ISVTX)
		ft_putchar('T');
	else if (buf->st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
	get_ext_attr(path, buf, ls);
}

void	get_group_per(char *path, struct stat *buf, t_ls *ls)
{
	if (buf->st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (buf->st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf->st_mode & S_IXGRP) && (buf->st_mode & S_ISGID))
		ft_putchar('s');
	else if (buf->st_mode & S_ISGID)
		ft_putchar('S');
	else if (buf->st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	get_other_per(path, buf, ls);
}

void	get_user_per(char *path, struct stat *buf, t_ls *ls)
{
	if (buf->st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (buf->st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf->st_mode & S_IXUSR) && (buf->st_mode & S_ISUID))
		ft_putchar('s');
	else if (buf->st_mode & S_ISUID)
		ft_putchar('S');
	else if (buf->st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	get_group_per(path, buf, ls);
}

void	get_mode(char *path, struct stat *buf, t_ls *ls)
{
	if (S_ISBLK(buf->st_mode))
		ft_putchar('b');
	else if (S_ISCHR(buf->st_mode))
		ft_putchar('c');
	else if (S_ISDIR(buf->st_mode))
		ft_putchar('d');
	else if (S_ISREG(buf->st_mode))
		ft_putchar('-');
	else if (S_ISSOCK(buf->st_mode))
		ft_putchar('s');
	else if (S_ISFIFO(buf->st_mode))
		ft_putchar('p');
	else if (S_ISLNK(buf->st_mode))
		ft_putchar('l');
	get_user_per(path, buf, ls);
}
