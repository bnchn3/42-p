#include "checker.h"

void	exec_command_2(char *command, t_check *check)
{
	if (ft_strcmp("rb", command) == 0)
		rotate_b(check);
	else if (ft_strcmp("rr", command) == 0)
	{
		rotate_a(check);
		rotate_b(check);
	}
	else if (ft_strcmp("rra", command) == 0)
		reverse_rotate_a(check);
	else if (ft_strcmp("rrb", command) == 0)
		reverse_rotate_b(check);
	else if (ft_strcmp("rrr", command) == 0)
	{
		reverse_rotate_a(check);
		reverse_rotate_b(check);
	}
	else
		check->error = 1;
}

void	exec_command(char *command, t_check *check)
{
	if (ft_strcmp("sa", command) == 0)
		swap_a(check);
	else if (ft_strcmp("sb", command) == 0)
		swap_b(check);
	else if (ft_strcmp("ss", command) == 0)
	{
		swap_a(check);
		swap_b(check);
	}
	else if (ft_strcmp("pa", command) == 0)
		push_a(check);
	else if (ft_strcmp("pb", command) == 0)
		push_b(check);
	else if (ft_strcmp("ra", command) == 0)
		rotate_a(check);
	else
		exec_command_2(command, check);
}

void	execute(t_check *check)
{
	t_list *tmp;

	tmp = check->commands;
	check->b = NULL;
	check->b_size = 0;
	while (tmp)
	{
		exec_command(tmp->content, check);
		tmp = tmp->next;
	}
}
