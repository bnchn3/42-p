/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:09:41 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 14:35:06 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_hour(int hour)
{
	if (hour == 24)
		hour = 0;
	if (hour > 12)
		printf("%d", hour - 12);
	else if (hour == 0)
		printf("%d", 12);
	else
		printf("%d", hour);
}

void	ft_takes_place(int hour)
{
	hour /= 100;
	printf("%s", "THE FOLLOWING TAKES PLACE BETWEEN ");
	ft_print_hour(hour);
	printf("%s", ".00 ");
	if (hour >= 12)
		printf("%s", "P.M. AND ");
	else
		printf("%s", "A.M. AND ");
	ft_print_hour(hour + 1);
	if (hour + 1 >= 12 && hour != 23)
		printf("%s", ".00 P.M.\n");
	else
		printf("%s", ".00 A.M.\n");
}
