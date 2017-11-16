/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:07:26 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 15:12:37 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*ptr;

	count = 0;
	if (begin_list != NULL)
	{
		ptr = begin_list;
		count++;
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return (count);
}
