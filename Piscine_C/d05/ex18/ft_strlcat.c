/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:34:01 by bchan             #+#    #+#             */
/*   Updated: 2017/10/31 18:27:17 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		len;
	unsigned int		dstlen;

	i = 0;
	len = 0;
	while (dest[i] != '\0' && i < size)
	{
		i++;
		len++;
	}
	dstlen = len;
	while (len < size && src[i - dstlen] != '\0')
	{
		dest[len] = src[i - dstlen];
		i++;
		len++;
	}
	if (len < size)
		dest[len] = '\0';
	j = 0;
	while (src[j] != '\0')
		j++;
	return (dstlen + j);
}
