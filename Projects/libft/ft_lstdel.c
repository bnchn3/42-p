/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:49:35 by bchan             #+#    #+#             */
/*   Updated: 2017/12/01 15:01:08 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (*alst)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		ft_lstdel(&next, del);
	}
}
