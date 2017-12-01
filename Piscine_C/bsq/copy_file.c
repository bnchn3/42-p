/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:23:52 by bchan             #+#    #+#             */
/*   Updated: 2017/11/15 13:55:05 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	pseudo_memcpy(char *out, char *in, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		out[i] = in[i];
		i++;
	}
}

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
		temp = malloc(buffer_size + br + 1);
		if (temp && input)
			pseudo_memcpy(temp, input, buffer_size);
		if (input)
			free(input);
		input = temp;
		if (!input)
			break ;
		pseudo_memcpy(input + buffer_size, buffer, br);
		buffer_size += br;
	}
	if (input)
		input[buffer_size] = '\0';
	return (input);
}
