/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:39:04 by bchan             #+#    #+#             */
/*   Updated: 2017/11/08 11:43:29 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*ptr;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	ptr = *begin_list;
	while (ptr != NULL && ptr->next != NULL)
	{
		if (cmp(ptr->next->data, data_ref) == 0)
		{
			tmp = ptr->next;
			ptr->next = tmp->next;
			free(tmp);
		}
		if (ptr->next != NULL)
			ptr = ptr->next;
	}
}
