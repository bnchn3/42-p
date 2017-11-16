/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:45:26 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 15:50:19 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*ptr;
	unsigned int	i;

	i = 0;
	ptr = begin_list;
	while (i < nbr)
	{
		if (ptr == NULL)
			return (NULL);
		ptr = ptr->next;
		i++;
	}
	return (ptr);
}
