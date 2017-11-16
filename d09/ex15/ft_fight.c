/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:10:13 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 16:18:29 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perso.h"
#include "ft_fight.h"

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

void	ft_fight(t_perso *p1, t_perso *p2, int attack)
{
	if (p1->life > 0 && p2->life > 0)
	{
		p2->life -= attack;
		ft_putstr(p1->name);
		ft_putstr(" does a judo ");
		if (attack == 15)
			ft_putstr("kick");
		else if (attack == 5)
			ft_putstr("punch");
		else if (attack == 20)
			ft_putstr("headbutt");
		ft_putstr(" on ");
		ft_putstr(p2->name);
		ft_putstr(".\n");
		if (p2->life <= 0)
		{
			ft_putstr(p2->name);
			ft_putstr(" is dead.\n");
		}
	}
}
