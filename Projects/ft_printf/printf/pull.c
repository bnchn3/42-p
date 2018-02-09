/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:31:26 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:35:38 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pull_int(t_print *form, va_list ap, char c)
{
	int		arg;
	char	*result;

	arg = va_arg(ap, int);
	if (c == 'd' || c == 'i')
		result = ft_itoa(arg);
	else
		result = ft_strdup(&arg);
	result = modify_string(form, result);
	return (result);
}

char	*pull_un_int(t_print *form, va_list ap, char c)
{
	unsigned int	arg;
	char			*result;
	int i;

	arg = va_arg(ap, unsigned int);
	if (c == 'u')
		result = ft_unsigned_itoa(arg);
	if (c == 'o')
		result = ft_octal_convert(arg);
	if (c == 'x')
		result = ft_hex_convert(arg);
	if (c == 'X')
	{
		i = 0;
		result = ft_hex_convert(arg);
		while (result[i])
		{
			result[i] = (char)ft_toupper(result[i]);
			i++;
		}
	}
	result = modify_string(form, result);
	return (result);
}

char	*pull_string(t_print *form, va_list ap)
{
	char	*arg;

	arg = ft_strdup(va_arg(ap, char *));
	arg = modify_string(form, arg);
	return (arg);
}

char	*pull_voidp(t_print *form, va_list ap)
{
	void	*arg;
	char	*result;
	char	*temp;

	arg = va_arg(ap, void *);
	temp = ft_hex_convert((unsigned int)arg);
	result = ft_strjoin("0x", temp);
	free(temp);
	result = modify_string(form, result);
	return (result);
}

char *pull_intp(t_print *form, va_list ap)
{
	int		*arg;

	arg = va_arg(ap, int *);
	*arg = ft_strlen(form->result);
	return (ft_strdup(""));
}
