/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:54:49 by bchan             #+#    #+#             */
/*   Updated: 2018/08/01 13:01:12 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **begin_list, t_list *new)
{
	t_list	*lst;

	lst = *begin_list;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}
