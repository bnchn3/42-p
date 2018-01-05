/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:25:41 by bchan             #+#    #+#             */
/*   Updated: 2018/01/05 14:00:11 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_newline(char *buffer)
{
	char	*result;
	int		count;

	count = 1;
	result = ft_strchr(buffer, '\n');
	if (result)
	{
		while (result != buffer)
		{
			result--;
			count++;
		}
		return (count);
	}
	return (0);
}

int		read_line(char *buffer, char **line, int br)
{
	static int	total_br;
	char		*temp;

	temp = (char *)malloc(total_br + br);
	if (temp && *line)
		ft_memcpy(temp, *line, total_br);
	if (*line)
		free(*line);
	*line = temp;
	ft_memcpy(*line + total_br, buffer, br);
	total_br += br;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE];
	int				br;

	br = 1;
	while (br > 0)
	{
		br = read(fd, buffer, BUFF_SIZE);
		if (br == -1)
			return (-1);
		if (br > 0)
		{
			if (find_newline(buffer) == 0)
				read_line(buffer, line, br);
			else
			{
				read_line(buffer, line, find_newline(buffer) - 1);
				return (1);
			}
		}
	}
	return (0);
}
