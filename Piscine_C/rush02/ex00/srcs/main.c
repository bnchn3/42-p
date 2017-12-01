/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:04:37 by ttran             #+#    #+#             */
/*   Updated: 2017/11/12 12:48:07 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush2tools.h"
#include "rush.h"

#define ERROR(x) if (x) write(2, "aucune\n", 7);

void	pseudo_memcpy(char *out, char *in, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		out[i] = in[i];
		i++;
	}
}

char	*copy_stdin(void)
{
	char			buffer[4096];
	char			*temp;
	char			*input;
	int				br;
	unsigned int	buffer_size;

	buffer_size = 0;
	br = 1;
	while (br > 0)
	{
		br = read(0, buffer, 4096);
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

char	*get_input_dimensions(int *x, int *y)
{
	int		i;
	char	*input;

	input = copy_stdin();
	if (input)
	{
		i = 0;
		*y = 0;
		while (input[i])
			if (input[i++] == '\n')
				(*y)++;
		*x = 0;
		while (input[*x] != '\n' && input[*x])
			(*x)++;
	}
	return (input);
}

int		main(void)
{
	int		x;
	int		y;
	char	*input;
	int		use_or;

	use_or = 0;
	input = get_input_dimensions(&x, &y);
	if (input)
	{
		if (strcmp_and_free(rush00(x, y), input) == 0)
			use_or = print_success('0', x, y, use_or);
		if (strcmp_and_free(rush01(x, y), input) == 0)
			use_or = print_success('1', x, y, use_or);
		if (strcmp_and_free(rush02(x, y), input) == 0)
			use_or = print_success('2', x, y, use_or);
		if (strcmp_and_free(rush03(x, y), input) == 0)
			use_or = print_success('3', x, y, use_or);
		if (strcmp_and_free(rush04(x, y), input) == 0)
			print_success('4', x, y, use_or);
		if (use_or)
			write(1, "\n", 1);
		free(input);
	}
	ERROR(!use_or);
	return (0);
}
