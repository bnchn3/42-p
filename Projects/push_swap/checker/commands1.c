#include "checker.h"

void	swap_a(t_check *check)
{
	t_list *tmp;

	if (check->a_size > 1)
	{
		tmp = check->a;
		check->a = check->a->next;
		tmp->next = check->a->next;
		check->a->next = tmp;
	}
}

void	swap_b(t_check *check)
{
	t_list *tmp;

	if (check->b_size > 1)
	{
		tmp = check->b;
		check->b = check->b->next;
		tmp->next = check->b->next;
		check->b->next = tmp;
	}
}

void	push_a(t_check *check)
{
	t_list *tmp;

	if (check->b_size > 0)
	{
		tmp = check->b->next;
		ft_lstadd(&(check->a), check->b);
		check->b = tmp;
		check->a_size++;
		check->b_size--;
	}
}

void	push_b(t_check *check)
{
	t_list *tmp;

	if (check->a_size > 0)
	{
		tmp = check->a->next;
		ft_lstadd(&(check->b), check->a);
		check->a = tmp;
		check->a_size--;
		check->b_size++;
	}
}

void	rotate_a(t_check *check)
{
	t_list *tmp;

	if (check->a_size > 1)
	{
		tmp = check->a;
		check->a = check->a->next;
		ft_lstadd_end(&(check->a), tmp);
	}
}
