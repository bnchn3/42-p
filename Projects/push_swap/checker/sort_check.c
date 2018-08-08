/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:58:43 by bchan             #+#    #+#             */
/*   Updated: 2018/08/01 12:58:50 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		sort_check(t_list *a)
{
	t_list *tmp;

	tmp = a;
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
		ft_memdel((void **)&(check->a->content));
		ft_memdel((void **)&(check->a));
		check->a = tmp;
	}
	while (check->b)
	{
		tmp = check->b->next;
		ft_memdel((void **)&(check->b->content));
		ft_memdel((void **)&(check->b));
		check->b = tmp;
	}
	while (check->commands)
	{
		tmp = check->commands->next;
		ft_memdel((void **)&(check->commands->content));
		ft_memdel((void **)&(check->commands));
		check->commands = tmp;
	}
	ft_memdel((void **)&check);
}
