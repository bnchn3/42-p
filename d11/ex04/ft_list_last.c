/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:13:21 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 15:17:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*ptr;

	if (begin_list == NULL)
		return (NULL);
	else
	{
		ptr = begin_list;
		while (ptr->next != NULL)
			ptr = ptr->next;
	}
	return (ptr);
}
