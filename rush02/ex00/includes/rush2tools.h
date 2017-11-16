/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:17:56 by ttran             #+#    #+#             */
/*   Updated: 2017/11/11 20:12:18 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH2TOOLS_H
# define RUSH2TOOLS_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		strcmp_and_free(char *s1, char *s2);
int		print_success(char n, int x, int y, int use_or);

#endif
