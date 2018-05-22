/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:14:08 by bchan             #+#    #+#             */
/*   Updated: 2018/05/21 12:35:15 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_file(char *str)
{
	struct stat	*buf;
	int			result;

	result = -1;
	buf = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(str, buf) == 0)
	{
		if (buf->st_mode & S_IFDIR)
			result = 0;
		else
			result = 1;
	}
	else
		perror(str);
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
		sort_files(ls->files, NULL, ls);
	if (ft_strrchr(ls->flags, 'l') > ft_strrchr(ls->flags, '1') ||
		ft_strchr(ls->flags, 'o'))
		print_files_long(ls);
	else
	{
		if (ft_strchr(ls->flags, '1'))
		{
			i = 0;
			while (i < ls->num_files)
				ft_putendl(ls->files[i++]);
		}
		else
			get_col(ls->files);
	}
	if (ls->num_dir > 0)
		ft_putchar('\n');
}

void	get_col(char **contents)
{
	struct winsize	w;
	int				col;
	int				pad;
	int				i;

	i = open("/dev/tty", O_RDONLY);
	ioctl(i, TIOCGWINSZ, &w);
	i = 0;
	while (contents[i])
		i++;
	pad = get_col_pad(contents) + 4;
	col = w.ws_col / pad;
	if (!col)
		col = 1;
	if (pad * i < w.ws_col)
		col = i;
	print_col(contents, col, pad);
}

void	print_col(char **contents, int col, int pad)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (contents[i])
	{
		j = 0;
		while (j++ < col && contents[i])
		{
			ft_putstr(contents[i]);
			len = ft_strlen(contents[i++]);
			while (len++ < pad)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
