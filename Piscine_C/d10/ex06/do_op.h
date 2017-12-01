/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:59:32 by bchan             #+#    #+#             */
/*   Updated: 2017/11/07 13:46:40 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_add(char *s1, char *s2);
int		ft_sub(char *s1, char *s2);
int		ft_mult(char *s1, char *s2);
int		ft_div(char *s1, char *s2);
int		ft_mod(char *s1, char *s2);

typedef int	(*t_ptr)(char *s1, char *s2);
#endif
