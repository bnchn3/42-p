/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:20:49 by bchan             #+#    #+#             */
/*   Updated: 2018/07/27 12:23:32 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../ft_printf/printf/libftprintf.h"

typedef struct	s_check
{
	t_list *a;
	t_list *b;
	int a_size;
	int b_size;
	t_list *commands;
}				t_check;

#endif
