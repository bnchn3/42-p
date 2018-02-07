/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:10:57 by bchan             #+#    #+#             */
/*   Updated: 2018/02/07 12:13:00 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int		find_zeroes(char *save)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (save[i] == ' ')
		i++;
	while (save[i] == '0')
	{
		count++;
		i++;
	}
	return (count);
}

int		find_digits(char *save)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (save[i] == '0' || save[i] == ' ')
		i++;
	while (ft_isdigit(save[i]))
	{
		count++;
		i++;
	}
	return (count);
}

char *find_save(char c, char *result, t_print *form)
{
	char	*save;

	save = result;
	while (!(ft_isdigit(*save)))
		save++;
	if (ft_strchr(form->flags, '#') && (c == 'x' || c == 'X'))
		save += 2;
	return (save);
}

void	remove_zero(t_print *form, char *save, char *result)
{
	char	*temp;

	ft_memmove(save, save + 1, ft_strlen(save));
	if (form->width)
	{
		temp = &(save[ft_strlen(save)]);
		if (ft_strchr(form->flags, '-'))
			ft_meminsert(temp, ' ', 1);
		else
			ft_meminsert(result, ' ', ft_strlen(result));
	}
}

char	*add_zero(t_print *form, char *save, char *result)
{
	char	*temp;

	while (find_digits(save) + find_zeroes(save) < form->precision)
	{
		ft_meminsert(save, '0', ft_strlen(save));
		if (form->width)
		{
			temp = &(save[ft_strlen(save)]);
			if (ft_strchr(form->flags, '-') && *(temp - 1) == ' ')
				ft_memmove(temp - 1, temp, 1);
			else if (!(ft_strchr(form->flags, '-')) && *result == ' ')
			{
				ft_memmove(result, result + 1, ft_strlen(result));
				save--;
			}
		}
	}
	save = ft_strdup(result);
	free(result);
	return (save);
}
