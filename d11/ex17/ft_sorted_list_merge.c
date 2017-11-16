/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:18:28 by bchan             #+#    #+#             */
/*   Updated: 2017/11/08 17:32:16 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
								t_list *begin_list2, int (*cmp)())
{
	t_list *ptr;
	t_list *ptr2;
	t_list *tmp;

	ptr = begin_list2;
	while (ptr->next)
		ptr = ptr->next;
	ptr2 = *begin_list1;
	while (ptr2->next)
	{
		if (cmp(ptr2->data, begin_list2->data) <= 0)
		{
			tmp = ptr2;
			while (tmp->next)
			{
				if (cmp(tmp->data, ptr->data) >= 0)
				{
					ptr2->next = begin_list2;
					ptr->next = tmp;
				}
			}
			tmp->next = begin_list2;
		}
	}
	ptr->next = *begin_list1;
}
