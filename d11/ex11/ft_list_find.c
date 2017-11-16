/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:34:26 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 16:37:54 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr != NULL)
	{
		if (cmp(ptr->data, data_ref) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
