/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:57:24 by bchan             #+#    #+#             */
/*   Updated: 2018/08/01 12:58:11 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_arg(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!(ft_isdigit(argv[i][j])))
			{
				if (j == 0 && argv[i][j++] == '-')
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

int		check_dup(int argc, char **argv)
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

t_list	*get_a(int argc, char **argv, t_check *check)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = argc - 1;
	if (!(check_arg(argc, argv)) || !(check_dup(argc, argv)))
	{
		check->error = 1;
		return (NULL);
	}
	while (i > 0)
	{
		ft_lstadd(&a, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
		i--;
	}
	return (a);
}

t_list	*get_commands(t_check *check)
{
	t_list	*commands;
	t_list	*temp;
	char	*line;
	int		i;

	while ((i = get_next_line(0, &line)))
	{
		if (i == -1)
		{
			check->error = 1;
			return (NULL);
		}
		ft_lstadd_end(&commands, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	return (commands);
}
