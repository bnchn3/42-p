/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:07:10 by bchan             #+#    #+#             */
/*   Updated: 2018/04/16 15:07:14 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_ls	*ls;
	char	*temp;
	int		i;

	ls = parse_flags(argv);
	parse_args(argc, argv, ls);
	if (ls->num_files > 0)
		print_files(ls);
	if (ls->num_dir == 0 && ls->num_files == 0)
	{
		ls->first = 0;
		temp = ft_strdup(".");
		list_dir(&temp, ls, NULL);
		ft_strdel(&temp);
	}
	else if (ls->num_dir > 0)
	{
		i = -1;
		sort_dir(ls);
		while (++i < ls->num_dir)
			if (valid_dir(ls->dirs[i]))
				list_dir(&(ls->dirs[i]), ls, NULL);
	}
	ls_del(ls);
	return (0);
}
