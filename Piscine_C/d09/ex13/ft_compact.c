/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:39:40 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 15:42:36 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compact(char **tab, int length)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
