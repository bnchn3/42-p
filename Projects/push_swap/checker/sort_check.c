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
	ft_lstdel(&(check->a));
	ft_lstdel(&(check->b));
	ft_lstdel(&(check->commands));
	ft_memdel((void **)&check);
}
