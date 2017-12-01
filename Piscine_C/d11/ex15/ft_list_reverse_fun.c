/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:20:23 by bchan             #+#    #+#             */
/*   Updated: 2017/11/08 16:38:20 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = begin_list;
	tmp = NULL;
	while (begin_list && begin_list->next)
	{
		begin_list = begin_list->next;
		ptr->next = tmp;
		tmp = ptr;
		ptr = begin_list;
	}
	if (begin_list)
		begin_list->next = tmp;
}
