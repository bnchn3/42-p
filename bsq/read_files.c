/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:28:04 by bchan             #+#    #+#             */
/*   Updated: 2017/11/15 13:53:19 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_list	*create_new_elem(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->next = NULL;
	list->data = NULL;
	return (list);
}

t_list	*read_files(char *str)
{
	int		fd;
	t_list	*list;

	list = create_new_elem();
	fd = open(str, O_RDONLY);
	if (fd != -1)
		list->data = copy_file(fd, 0);
	return (list);
}
