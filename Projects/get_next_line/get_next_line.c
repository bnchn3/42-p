/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:15:46 by bchan             #+#    #+#             */
/*   Updated: 2018/01/18 15:10:45 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_file(int fd, t_list **file)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static int		find_newline(char *buffer)
{
	char	*result;
	int		count;

	count = ft_strlen(buffer);
	result = ft_strchr(buffer, '\n');
	if (result)
	{
		while (*result != '\0')
		{
			result++;
			count--;
		}
	}
	return (count);
}

static char		*read_line(char *buffer, char *line, int br)
{
	char		*temp;

	temp = ft_strnew(ft_strlen(line) + br);
	if (temp && line)
		ft_memcpy(temp, line, ft_strlen(line));
	if (line)
		free(line);
	line = temp;
	ft_memcpy(line + ft_strlen(line), buffer, br);
	return (line);
}

static char		*advance_line(int len, char *line)
{
	char	*temp;
	int		i;

	i = ft_strlen(line) - len - 1;
	temp = ft_strnew(i);
	if (temp && line)
		ft_memcpy(temp, line + len + 1, i);
	if (line)
		free(line);
	line = temp;
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			buffer[BUFF_SIZE];
	int				br;
	int				len;
	t_list			*tmp;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	tmp = get_file(fd, &file);
	*line = ft_strnew(1);
	while ((br = read(fd, buffer, BUFF_SIZE)))
	{
		tmp->content = read_line(buffer, tmp->content, br);
		if (ft_strchr(tmp->content, '\n'))
			break ;
	}
	if (br < BUFF_SIZE && ft_strlen(tmp->content) == 0)
		return (0);
	len = find_newline(tmp->content);
	*line = read_line(tmp->content, *line, len);
	if (len < (int)ft_strlen(tmp->content))
		tmp->content = advance_line(len, tmp->content);
	else
		ft_strclr(tmp->content);
	return (1);
}
