/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:18:40 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 15:39:11 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*ptr;
	t_list	*tmp;

	i = 2;
	ptr = NULL;
	if (ac >= 2)
		ptr = ft_create_elem(av[1]);
	while (i < ac)
	{
		tmp = ptr;
		ptr = ft_create_elem(av[i]);
		ptr->next = tmp;
		i++;
	}
	return (ptr);
}
