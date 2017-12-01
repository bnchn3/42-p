/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:59:56 by bchan             #+#    #+#             */
/*   Updated: 2017/11/10 13:29:39 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int		count;
	t_btree	*node;

	count = 0;
	node = root;
	while (node)
	{
		if (node->left)
		{
			node = node->left
