/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:43:34 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 15:43:47 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_octal_convert(uintmax_t n)
{
	char	*result;
	char	*digit;

	result = ft_strdup("");
	if (n == 0)
		ft_strpstr(&result, "0");
	while (n > 0)
	{
		digit = ft_unsigned_itoa(n % 8);
		ft_strpstr(&result, digit);
		free(digit);
		n /= 8;
	}
	result = ft_strrev(result);
	return (result);
}
