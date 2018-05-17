/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:12:25 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:12:28 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_del(t_ls *ls)
{
	int	i;

	i = 0;
	if (ls->flags)
		ft_strdel(&(ls->flags));
	if (ls->dirs)
	{
		while (i < ls->num_dir)
			ft_strdel(&(ls->dirs[i++]));
		ft_memdel((void **)&(ls->dirs));
	}
	if (ls->files)
	{
		i = 0;
		while (i < ls->num_files)
			ft_strdel(&(ls->files[i++]));
		ft_memdel((void **)&(ls->files));
	}
	ft_memdel((void **)&(ls));
}

void	char_del(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_strdel(&(str[i++]));
		ft_memdel((void **)&str);
	}
}
