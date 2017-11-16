/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:51:52 by bchan             #+#    #+#             */
/*   Updated: 2017/11/15 14:03:15 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

t_coor	*new_coor(t_coor *sq, int x, int y, int dimen)
{
	sq->coor[0] = x;
	sq->coor[1] = y;
	sq->dimen = dimen;
	return (sq);
}

t_coor	*check_square(char **str, int x, int y, t_coor *sq)
{
	int		i;
	int		j;
	int		dimen;

	dimen = sq->dimen - 1;
	while (++dimen <= (ft_atoi(str[0]) - y + 2) &&
			dimen <= (ft_strlen(str[y]) - x))
	{
		i = -1;
		while (++i < dimen)
		{
			j = -1;
			while (++j < dimen)
			{
				if (check_obstacle(str, y + i, x + j))
				{
					if ((dimen - 1) > sq->dimen)
						return (new_coor(sq, x, y, (dimen - 1)));
					else
						return (sq);
				}
			}
		}
	}
	return (sq);
}

void	print_map(char **str, t_coor *sq)
{
	int		i;
	int		j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (i >= sq->coor[1] && i < sq->coor[1] + sq->dimen &&
					j >= sq->coor[0] && j < sq->coor[0] + sq->dimen)
				write(1, &str[0][ft_strlen(str[0]) - 1], 1);
			else
				write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	free(sq);
	free(str);
}

void	solve_bsq(char **str)
{
	int		x;
	int		y;
	t_coor	*sq;

	sq = malloc(sizeof(t_coor));
	if (check_map(str) == 1)
	{
		y = 1;
		sq->coor[0] = 0;
		sq->coor[1] = y;
		sq->dimen = 1;
		while (str[y])
		{
			x = 0;
			while (str[y][x])
			{
				sq = check_square(str, x, y, sq);
				x++;
			}
			y++;
		}
		print_map(str, sq);
	}
	else
		write(2, "map error\n", 11);
}

int		main(int argc, char **argv)
{
	t_list	*input;
	t_list	*tmp;
	int		count;

	input = create_new_elem();
	count = 1;
	if (argc < 2)
		input->data = copy_file(0, 0);
	else
		input = read_files(argv[1]);
	while (count < argc || input->data != NULL)
	{
		solve_bsq(ft_split_whitespaces(input->data));
		if (count++ < argc - 1)
			write(1, "\n", 1);
		if (argv[count])
		{
			tmp = input;
			input = read_files(argv[count]);
			free(tmp);
		}
		else
			break ;
	}
	return (0);
}
