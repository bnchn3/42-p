/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:01:45 by fclaude           #+#    #+#             */
/*   Updated: 2017/11/05 20:16:52 by aisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** This function is the standard putchar. It will take a character as an
** argument and write it to the standard output.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** This function will write a string to the standard output. It does this by
** going through the string character by character and using ft_putchar to
** write each one to the standard output.
*/

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*
** This function returns the length of the string it is given. It does this
** iterating a counter while moving through the string character by character.
*/

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
