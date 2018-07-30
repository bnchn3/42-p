#include "checker.h"

int	sort_check(t_check *check)
{
	t_list *tmp;

	tmp = check->a;
	if (check->b_size != 0 || check->b != NULL)
		return (0);
	while (tmp->next)
	{
		if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_del(t_check *check)
{
	t_list *tmp;

	while (check->a)
	{
		tmp = check->a->next;
		ft_memdel(&(check->a->content));
		ft_memdel(&(check->a));
		check->a = tmp;
	}
	while (check->b)
	{
		tmp = check->b->next;
		ft_memdel(&(check->b->content));
		ft_memdel(&(check->b));
		check->b = tmp;
	}
	while (check->commands)
	{
		tmp = check->commands->next;
		ft_memdel(&(check->commands->content));
		ft_memdel(&(check->commands));
		check->commands = tmp;
	}
	ft_memdel(&check);
}
