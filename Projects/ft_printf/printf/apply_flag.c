/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:04:04 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:06:17 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*force_dec(char *result)
{
	int	i;

	i = 0;
	while(result[i])
	{
		if (result[i] == '.')
			return (result);
		i++;
	}
	ft_strpstr(&result, ".");
	return (result);
}

char	*apply_pound(char c, char *result)
{
	char	*tmp1;
	char	*tmp2;

	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'f' || c == 'F'
		|| c == 'g' || c == 'G')
		return (force_dec(result));
	if (c == 'd' || c == 'i')
		return (result);
	tmp1 = ft_strdup(result);
	tmp2 = result;
	if ((c == 'o' || c == 'O') && ft_atoi(result) != 0)
		tmp2 = ft_strjoin("0", tmp1);
	if (c == 'x' && result[0] != '0')
		tmp2 = ft_strjoin("0x", tmp1);
	if (c == 'X' && result[0] != '0')
		tmp2 = ft_strjoin("0X", tmp1);
	ft_strcpy(result, tmp2);
	free(tmp1);
	free(tmp2);
	return (ft_strdup(result));
}

char *apply_flag(t_print *form, char *result)
{
	char *temp;

	temp = NULL;
	if (form->spec == 'd' || form->spec == 'i')
	{
		if (ft_strchr(form->flags, '+') && ft_atoi(result) >= 0)
			temp = ft_strjoin("+", result);
		else if (ft_strchr(form->flags, ' ') && ft_atoi(result) >= 0)
			temp = ft_strjoin(" ", result);
	}
	if (ft_strchr(form->flags, '#') && number_spec(form->spec))
		temp = apply_pound(form->spec, result);
	if (temp && temp != result)
	{
		free(result);
		result = temp;
	}
	return (result);
}
