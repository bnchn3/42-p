/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:14:08 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:35:17 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_file(char *str)
{
	struct stat	*buf;
	int			result;

	buf = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(str, buf) == 0)
	{
		if (buf->st_mode & S_IFDIR)
			result = 0;
		else
			result = 1;
	}
	else
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	ft_memdel((void **)&buf);
	return (result);
}

void	print_files_long(t_ls *ls)
{
	struct stat	*buf;
	int			i;

	i = 0;
	buf = (struct stat *)malloc(sizeof(struct stat));
	get_pads(ls, ls->files, "", buf);
	while (i < ls->num_files)
	{
		if (lstat(ls->files[i], buf) == 0)
		{
			get_mode(ls->files[i], buf, ls);
			get_name(ls->files[i], ls->files[i], buf, ls);
		}
		else
		{
			perror("stat");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_memdel((void **)&buf);
}

void	print_files(t_ls *ls)
{
	int	i;

	alpha_sort(ls->files);
	if (ft_strchr(ls->flags, 'r') || ft_strchr(ls->flags, 't'))
		sort_files(ls->files, ls);
	if (ft_strrchr(ls->flags, 'l') > ft_strrchr(ls->flags, '1'))
		print_files_long(ls);
	else
	{
		i = 0;
		while (i < ls->num_files)
			ft_putendl(ls->files[i++]);
	}
	if (ls->num_dir > 0)
		ft_putchar('\n');
}
