/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:53:50 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 13:58:18 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int		temp1;
	int		temp2;

	temp1 = *******c;
	*******c = ***a;
	temp2 = ****d;
	****d = temp1;
	temp1 = *b;
	*b = temp2;
	***a = temp1;
}