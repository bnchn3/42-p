/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:27:01 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:40:35 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ft_intlen(uintmax_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	while (n != 0)
	{
		n /= (unsigned int)10;
		len++;
	}
	return (len);
}

char	**read_dir(char *path, t_ls *ls)
{
	int				count;
	char			**contents;
	DIR				*dir;
	struct dirent	*entry;

	count = 0;
	dir = opendir(path);
	while (readdir(dir))
		count++;
	closedir(dir);
	contents = (char **)malloc(sizeof(char *) * (count + 1));
	count = 0;
	dir = opendir(path);
	while ((entry = readdir(dir)))
	{
		if (ft_strchr(ls->flags, 'a') || entry->d_name[0] != '.')
			contents[count++] = ft_strdup(entry->d_name);
	}
	contents[count] = NULL;
	closedir(dir);
	return (contents);
}

char	**copy_2d(char **contents)
{
	int		i;
	int		j;
	char	**sub;

	i = 0;
	j = 0;
	while (contents[i])
		i++;
	sub = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < i)
		sub[j++] = NULL;
	sub[i] = NULL;
	return (sub);
}

void	get_dir_size(char **contents, char *path, struct stat *buf)
{
	uintmax_t	size;
	char		*temp;
	int			i;

	size = 0;
	i = 0;
	ft_putstr("total ");
	while (contents[i])
	{
		temp = ft_strjoin(path, contents[i++]);
		if (lstat(temp, buf) == 0)
			size += buf->st_blocks;
		else
			perror("temp");
		ft_strdel(&temp);
	}
	temp = ft_unsigned_itoa(size);
	ft_putendl(temp);
	ft_strdel(&temp);
}
