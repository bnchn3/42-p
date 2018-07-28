/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:20:26 by bchan             #+#    #+#             */
/*   Updated: 2018/07/27 12:20:29 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_arg(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (!(ft_isdigit(argv[i][j])))
			{
				if (j == 0 && argv[i][j] == '-')
					continue ;
				else
					return (0);
			}
			j++;
		}
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*get_a(int argc, char **argv)
{
	t_list	*a;
	int	i;

	a = ft_lstnew(NULL, 0);
	i = argc - 1;
	if (!(check_arg(argc, argv)) || !(check_dup(argc, argv)))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	while (i > 0)
	{
		ft_lstadd(&a, ft_lstnew(ft_atoi(argv[i]), sizeof(int)));
		i--;
	}
	return (a);
}

int main (int argc, char **argv)
{
	t_check	*check;
	char	**line;

	if (argc == 1)
		exit(EXIT_FAILURE);
	check = (t_check *)malloc(sizeof(t_check));
	check->a = get_a(argc, argv);
	check->a_size = argc - 1;
	while (get_next_line(0, line))
		;
}
