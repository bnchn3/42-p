/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:24:50 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:32:00 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	get_time(char *str, t_ls *ls)
{
	time_t		t;
	struct stat	*buf;

	buf = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(str, buf) == 0)
	{
		if (ft_strrchr(ls->flags, 'c') > ft_strrchr(ls->flags, 'u'))
			t = buf->st_ctimespec.tv_sec;
		else if (ft_strrchr(ls->flags, 'u') > ft_strrchr(ls->flags, 'c'))
			t = buf->st_atimespec.tv_sec;
		else
			t = buf->st_mtimespec.tv_sec;
	}
	else
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	ft_memdel((void **)&buf);
	return (t);
}

void	get_name(char *abs_path, char *path, struct stat *buf, t_ls *ls)
{
	char	buf2[PATH_MAX];
	ssize_t	len;

	ft_putstr(path);
	if (S_ISLNK(buf->st_mode))
	{
		ft_putstr(" -> ");
		len = readlink(abs_path, buf2, PATH_MAX);
		if (len != -1)
		{
			buf2[len] = '\0';
			ft_putstr(buf2);
		}
		else
		{
			perror(abs_path);
			exit(EXIT_FAILURE);
		}
	}
	ft_putchar('\n');
	if ((ft_strchr(ls->flags, '@')) || (ft_strchr(ls->flags, 'e')))
		print_xattr(abs_path, ls);
}

void	get_year(time_t t, char *temp, time_t *t2, int i)
{
	if (t - *t2 > 15778800 || *t2 - t > 15778800)
	{
		i = 19;
		while (i < 24)
			ft_putchar(temp[i++]);
	}
	else
	{
		while (i < 16)
			ft_putchar(temp[i++]);
	}
	ft_putchar(' ');
	ft_memdel((void **)&t2);
}

void	get_time_long(char *path, t_ls *ls)
{
	time_t	t;
	char	*temp;
	time_t	*t2;
	int		i;

	t2 = (time_t *)malloc(sizeof(time_t));
	t = get_time(path, ls);
	temp = ctime(&t);
	i = 4;
	while (i < 11)
		ft_putchar(temp[i++]);
	*t2 = time(t2);
	get_year(t, temp, t2, i);
}
