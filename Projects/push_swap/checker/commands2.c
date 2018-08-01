/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:56:54 by bchan             #+#    #+#             */
/*   Updated: 2018/08/01 12:57:01 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_b(t_check *check)
{
	t_list *tmp;

	if (check->b_size > 1)
	{
		tmp = check->b;
		check->b = check->b->next;
		ft_lstadd_end(&(check->b), tmp);
	}
}

void	reverse_rotate_a(t_check *check)
{
	t_list *tmp;

	if (check->a_size > 1)
	{
		tmp = check->a;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd(&(check->a), tmp->next);
		tmp->next = NULL;
	}
}

void	reverse_rotate_b(t_check *check)
{
	t_list *tmp;

	if (check->b_size > 1)
	{
		tmp = check->b;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd(&(check->b), tmp->next);
		tmp->next = NULL;
	}
}
