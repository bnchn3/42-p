/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:49:16 by bchan             #+#    #+#             */
/*   Updated: 2017/11/08 14:19:32 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	void	*tmp;

	ptr = *begin_list;
	while (ptr != NULL && ptr->next != NULL)
	{
		if (cmp(ptr->data, ptr->next->data) > 0)
		{
			tmp = ptr->data;
			ptr->data = ptr->next->data;
			ptr->next->data = tmp;
			ptr = *begin_list;
		}
		else
			ptr = ptr->next;
	}
}
