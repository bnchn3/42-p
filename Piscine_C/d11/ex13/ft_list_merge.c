/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:40:37 by bchan             #+#    #+#             */
/*   Updated: 2017/11/08 11:47:33 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*ptr;

	ptr = *begin_list1;
	if (ptr == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = begin_list2;
}
