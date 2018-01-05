/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:53:17 by bchan             #+#    #+#             */
/*   Updated: 2017/11/10 11:58:39 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (root)
	{
		ft_btree_search_item(root->left, data_ref, cmpf);
		if (cmpf(data_ref, root->item) == 0)
			return (root);
		ft_btree_search_item(root->right, data_ref, cmpf);
	}
	return (0);
}
