/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:19:43 by bchan             #+#    #+#             */
/*   Updated: 2017/11/10 11:33:37 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		ft_btree_apply_infix(root->left, applyf);
		applyf(root->item);
		ft_btree_apply_infix(root->right, applyf);
	}
}
