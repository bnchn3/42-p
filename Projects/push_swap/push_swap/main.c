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

char	*get_last(t_list *a)
{
	t_list *tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->content);
}

int		reverse_sort_check(t_list *b)
{
	t_list *temp;

	temp = b;
	while (temp->next)
	{
		if (ft_atoi(temp->content) < ft_atoi(temp->next->content))
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	find_solution_1(t_check *one)
{
	char *temp;

	temp = NULL;
	if (sort_check(one->a->next) && ft_atoi(one->a->content) > ft_atoi(get_last(one->a)) &&
		reverse_sort_check(one->b->next) && ft_atoi(one->b->content) < ft_atoi(get_last(one->b)))
		temp = "rr";
	else if (sort_check(one->a->next) && ft_atoi(one->a->content) > ft_atoi(get_last(one->a)))
		temp = "ra";
	else if (reverse_sort_check(one->b->next) && ft_atoi(one->b->content) < ft_atoi(get_last(one->b)))
		temp = "rb";
	else if (ft_atoi(one->a->content) > ft_atoi(one->a->next->content) &&
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
	else if (!(sort_check(one->a)))
		temp = "pb";
	else if (one->b != NULL)
		temp = "pa";
	if (temp)
	{
		exec_command(temp, one);
		ft_lstadd_end(&(one->commands), ft_lstnew(temp, ft_strlen(temp) + 1));
		one->c_size++;
		find_solution_1(one);
	}
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
