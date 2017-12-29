/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:40:23 by bchan             #+#    #+#             */
/*   Updated: 2017/12/29 14:22:17 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_characters(char *file_string)
{
	while (*file_string)
	{
		if (*file_string != '#' && *file_string != '\n'
				&& *file_string != '.')
			return (0);
		file_string++;
	}
	return (1);
}

int	check_newlines(char *file_string)
{
	int	index;

	index = 20;
	while (file_string[index])
	{
		if (file_string[index] != '\n')
			return (0);
		if (file_string[index + 1] == '\0')
			return (0);
		index += 21;
	}
	return (1);
}

int	check_block_count(char *file_string)
{
	int	block_count;
	int	newline_count;

	newline_count = 0;
	block_count = 0;
	while (*file_string)
	{
		if (*file_string == '#')
			block_count++;
		if (*file_string == '\n')
		{
			newline_count++;
			if (newline_count == 4)
			{
				if (block_count != 4)
					return (0);
				block_count = 0;
				newline_count = 0;
				file_string++;
			}
		}
		file_string++;
	}
	return (1);
}

int	check_line_count(char *file)
{
	int	line_count;

	line_count = 0;
	while (*file)
	{
		if (*file != '\n')
		{
			line_count++;
			while (*file && *file != '\n')
			{
				file++;
			}
		}
		else
		{
			while (*file && *file == '\n')
				file++;
		}
	}
	if (line_count % 4 == 0)
		return (line_count / 4);
	else
		return (-1);
}

int	check_width(char *file_string)
{
	int	width;

	width = 0;
	while (*file_string)
	{
		if (*file_string == '\n')
		{
			if (width != 4)
				return (0);
			while (*file_string && *file_string == '\n')
				file_string++;
			width = 0;
		}
		else
		{
			width++;
			file_string++;
		}
	}
	return (1);
}
