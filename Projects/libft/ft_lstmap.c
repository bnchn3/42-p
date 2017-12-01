/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:59:35 by bchan             #+#    #+#             */
/*   Updated: 2017/12/01 14:54:31 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*newlist;

	if (lst)
	{
		newlist = ft_lstnew(lst->content, lst->content_size);
		if (!newlist)
			return (NULL);
		newlist = f(newlist);
		list = newlist->next;
		lst = lst->next;
		while (lst)
		{
			list = ft_lstnew(lst->content, lst->content_size);
			if (!list)
				return (NULL);
			list = f(list);
			list = list->next;
			lst = lst->next;
		}
		return (newlist);
	}
	return (NULL);
}
