/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:39:57 by bchan             #+#    #+#             */
/*   Updated: 2017/11/08 17:31:19 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *begin_list;
	while (ptr)
	{
		if (cmp(ptr->data, data) <= 0 || ptr->next == NULL)
		{
			tmp = ptr->next;
			ptr->next = ft_create_elem(data);
			ptr->next->next = tmp;
			break ;
		}
		ptr = ptr->next;
	}
}
