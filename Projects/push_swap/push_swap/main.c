/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:37:52 by bchan             #+#    #+#             */
/*   Updated: 2018/08/06 12:37:54 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_solution_1(t_check *one)
{
	char *temp;

	if (ft_atoi(one->a->content) > ft_atoi(one->a->next->content) &&
			ft_atoi(one->b->content) < ft_atoi(one->b->next->content))
		temp = "ss";
	else if (ft_atoi(one->a->content) > ft_atoi(one->a->next->content))
		temp = "sa";
	else if (ft_atoi(one->b->content) < ft_atoi(one->b->next->content))
		temp = "sb";
	else if (ft_atoi(one->a->content) > ft_atoi(get_last(one->a)) &&
				ft_atoi(one->b->content) < ft_atoi(get_last(one->b)))
		temp = "rrr";
	else if (ft_atoi(one->a->content) > ft_atoi(get_last(one->a)))
		temp = "rra";
	else if (ft_atoi(one->b->content) < ft_atoi(get_last(one->b)))
		temp = "rrb";
	else if ()
}

void	print_commands(t_list *commands)
{
	t_list	*temp;

	temp = commands;
	while (temp)
	{
		ft_putendl(temp->content);
		temp = temp->next;
	}
}

int 	main(int argc, char **argv)
{
	t_check *one;
	t_check *two;

	if (argc == 1)
		exit(EXIT_FAILURE);
	one = create_check(argc, argv);
	two = create_check(argc, argv);
	if (one->error == 1)
		ft_putendl_fd("Error", 2);
	else
	{
		find_solution_1(one);
		find_solution_2(two);
		if (one->c_size > two->c_size)
			print_commands(one->commands);
		else
			print_commands(two->commands);
	}
	check_del(one);
	check_del(two);
	return (1);
}
