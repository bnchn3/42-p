/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:20:28 by bchan             #+#    #+#             */
/*   Updated: 2017/12/18 12:09:03 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

/*
** This function will go through the file indicated by fd and write the file
** to a malloc'd string to be returned. This is done through a loop of read
** and write commands that will go through the file until no bytes are left
** to be read. The data is bounced between the temp and input strings in
** order to use the least amount of allocated memory possible.
*/

char	*copy_file(int fd, unsigned int buffer_size)
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

/*
** This function will give the number of tetriminos to be solved. It takes
** a single string (assumed to be valid) as input. It will first skip through
** any leading newlines, then walk through the string and iterate a counter
** when two consecutive newlines (denoting the end of a tetrimino) are
** encountered.
*/

int		tetcount(char *tetri)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tetri[i] == '\n')
		i++;
	while (tetri[i])
	{
		if (tetri[i] == '\n' && tetri[i - 1] == '\n')
			count++;
		i++;
	}
	return (count);
}

/*
** This simple function just opens the file pointed at by the filename
** given as a parameter. If the file is valid and there are no errors in
** opening it, the copy_file function is called on to write the contents of
** the file to the result string, which is then returned. If any errors
** occurred in the opening or copying, NULL is returned.
*/

char	*read_file(char *str)
{
	int		fd;
	char	*result;

	result = NULL;
	fd = open(str, O_RDONLY);
	if (fd != -1)
		result = copy_file(fd, 0);
	return (result);
}
