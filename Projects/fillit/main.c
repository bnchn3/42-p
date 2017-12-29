/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:03:29 by bchan             #+#    #+#             */
/*   Updated: 2017/12/29 15:18:03 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*tetri;

	if (argc != 2)
		ft_putendl("usage: ./fillit file_name");
	else
	{
		tetri = read_file(argv[1]);
		if (!(check_file(tetri)))
			ft_putendl("error");
		else
			print_square(tetri);
	}
	return (0);
}
