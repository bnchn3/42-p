/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:51:24 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 16:15:47 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*ptr;
	t_list	*tmp;
	t_list	*rev_tmp;

	tmp = *begin_list;
	ptr = NULL;
	while (tmp != NULL)
	{
		rev_tmp = ptr;
		ptr = tmp;
		tmp = tmp->next;
		ptr->next = rev_tmp;
	}
	*begin_list = ptr;
}
