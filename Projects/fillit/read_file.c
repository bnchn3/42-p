/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:20:28 by bchan             #+#    #+#             */
/*   Updated: 2017/12/13 13:39:52 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#define BUF_SIZE 1

static char	*copy_file(int fd, unsigned int buffer_size)
{
	char			buffer[4096];
	char			*temp;
	char			*input;
	int				br;

	input = 0;
	br = 1;
	while (br > 0)
	{
		br = read(fd, buffer, 4096);
		temp = (char *)malloc(buffer_size + br + 1);
		if (temp && input)
			ft_memcpy(temp, input, buffer_size);
		if (input)
			free(input);
		input = temp;
		if (!input)
			break ;
		ft_memcpy(input + buffer_size, buffer, br);
		buffer_size += br;
	}
	if (input)
		input[buffer_size] = '\0';
	return (input);
}

static int	tetcount(char **tmp2)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tmp2[i][0] == '\0')
		i++;
	while (tmp2[i])
	{
		if (tmp2[i][0] == '\0')
			count++;
		i++;
	}
	return (count + 1);
}

static char	***split_split(char **tmp2, char ***result)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (tmp2[j][0] == '\0')
		j++;
	while (result[i] && tmp[j])
	{
		result[i] = &(tmp[j]);
		i++;
		while (tmp[j][0] != '\0')
			j++;
		j++;
	}
	return (result);
}

char		***read_file(char *str);
{
	int		fd;
	char	*tmp;
	char	**tmp2;
	char	***result;

	result = NULL;
	fd = open(str, O_RDONLY);
	if (fd != -1)
	{
		tmp = copy_file(fd, 0);
		tmp2 = ft_strsplit(tmp, '\n');
		result = (char ***)malloc(sizeof(char **) * tetcount(tmp2));
		result = split_split(tmp2, result);
		free(tmp);
	}
	return (result);
}
