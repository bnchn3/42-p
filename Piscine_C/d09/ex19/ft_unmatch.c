/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:27:03 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 15:35:21 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int		i;
	int		j;
	int		k;
	int		count;

	i = 0;
	while (tab[i])
	{
		j = tab[i];
		k = 0;
		while (tab[k])
		{
			if (tab[k] == j)
				count++;
			k++;
		}
		if (count % 2 == 1)
			return (j);
		i++;
		count = 0;
	}
	return (0);
}
