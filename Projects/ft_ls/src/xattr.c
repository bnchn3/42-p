/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:11:44 by bchan             #+#    #+#             */
/*   Updated: 2018/05/21 12:35:31 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_xattr_2(char *path, t_ls *ls, char *namebuf, ssize_t max)
{
	ssize_t	size;
	int		i;
	int		pad;

	i = 0;
	while (namebuf[i])
	{
		ft_putstr("        ");
		ft_putstr(&(namebuf[i]));
		size = getxattr(path, &(namebuf[i]), NULL, 0, 0, XATTR_NOFOLLOW);
		pad = 9 + ls->link_pad + ls->user_pad + ls->group_pad -
			ft_strlen(&(namebuf[i])) - ft_intlen(size);
		while (pad-- > 0)
			ft_putchar(' ');
		ft_putnbr(size);
		ft_putchar('\n');
		while (namebuf[i] != '\0')
			i++;
		i++;
		if (i >= max)
			break ;
	}
}

void	print_xattr(char *path, t_ls *ls)
{
	char	*namebuf;
	ssize_t	size;

	if (ft_strchr(ls->flags, '@'))
	{
		size = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
		if (size > 0)
		{
			namebuf = (char *)malloc(size);
			listxattr(path, namebuf, size, XATTR_NOFOLLOW);
			print_xattr_2(path, ls, namebuf, size);
			ft_strdel(&namebuf);
		}
	}
	print_acl(path, ls);
}

void	print_acl(char *path, t_ls *ls)
{
	acl_t	acl;
	char	*s;

	if (ft_strchr(ls->flags, 'e'))
	{
		acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
		if (acl && acl_valid(acl) == 0)
		{
			ft_putchar(' ');
			s = acl_to_text(acl, NULL);
			if (s)
			{
				ft_putstr(&(s[8]));
				acl_free(s);
			}
			acl_free(acl);
		}
	}
}
