/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:20:26 by bchan             #+#    #+#             */
/*   Updated: 2018/08/01 13:35:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_check	*create_check(int argc, char **argv)
{
	t_check *check;

	check = (t_check *)malloc(sizeof(t_check));
	check->error = 0;
	check->a = get_a(argc, argv, check);
	check->a_size = argc - 1;
	check->b = NULL;
	check->b_size = 0;
	check->commands = NULL;
	check->c_size = 0;
	return (check);
}

int		main(int argc, char **argv)
{
	t_check	*check;

	if (argc == 1)
		exit(EXIT_FAILURE);
	check = create_check(argc, argv);
	if (check->error == 1)
	{
		ft_putendl_fd("Error", 2);
		check_del(check);
		return (0);
	}
	check->commands = get_commands(check);
	execute(check);
	if (check->error == 1)
		ft_putendl_fd("Error", 2);
	else if (sort_check(check->a) && check->b == NULL)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	check_del(check);
	return (1);
}
