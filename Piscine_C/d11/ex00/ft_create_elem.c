/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:04:03 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 14:29:16 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list		*elem;

	elem = malloc(sizeof(t_list));
	if (elem != NULL)
	{
		elem->next = NULL;
		elem->data = data;
	}
	return (elem);
}
