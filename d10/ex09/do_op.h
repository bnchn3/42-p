/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:59:32 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 12:51:05 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_atoi(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_add(char *s1, char *s2);
int				ft_sub(char *s1, char *s2);
int				ft_mul(char *s1, char *s2);
int				ft_div(char *s1, char *s2);
int				ft_mod(char *s1, char *s2);
int				ft_usage(char *s1, char *s2);

typedef int		(*t_ptr)(char *s1, char *s2);
typedef struct	s_opp
{
	char		*opp;
	t_ptr		fp;
}				t_opp;
#endif
