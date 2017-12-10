/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:34:56 by bchan             #+#    #+#             */
/*   Updated: 2017/11/10 11:52:27 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (*root == 0)
		*root = ft_btree_create_node(item);
	else if (cmpf(item, (*root)->item) < 0)
		ft_btree_insert_data(&(*root)->left, item, cmpf);
	else if (cmpf(item, (*root)->item) >= 0)
		ft_btree_insert_data(&(*root)->right, item, cmpf);
}
