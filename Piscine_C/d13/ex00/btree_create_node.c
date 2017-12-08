/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:02:13 by bchan             #+#    #+#             */
/*   Updated: 2017/11/10 11:06:40 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree		*node;

	node = (t_btree *)malloc(sizeof(t_btree *));
	if (node)
	{
		node->left = NULL;
		node->right = NULL;
		node->item = item;
	}
	return (node);
}
