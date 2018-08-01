/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:20:49 by bchan             #+#    #+#             */
/*   Updated: 2018/08/01 13:00:26 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../ft_printf/printf/libftprintf.h"

typedef struct		s_check
{
	t_list			*a;
	t_list			*b;
	unsigned int	a_size;
	unsigned int	b_size;
	t_list			*commands;
	int				error;
}					t_check;

t_check				*create_check(int argc, char **argv);
int					check_arg(int argc, char **argv);
int					check_dup(int argc, char **argv);
t_list				*get_a(int argc, char **argv, t_check *check);
t_list				*get_commands(t_check *check);

void				swap_a(t_check *check);
void				swap_b(t_check *check);
void				push_a(t_check *check);
void				push_b(t_check *check);
void				rotate_a(t_check *check);
void				rotate_b(t_check *check);
void				reverse_rotate_a(t_check *check);
void				reverse_rotate_b(t_check *check);

void				execute(t_check *check);
void				exec_command(char *command, t_check *check);
void				exec_command_2(char *command, t_check *check);

int					sort_check(t_check *check);
void				check_del(t_check *check);

#endif
