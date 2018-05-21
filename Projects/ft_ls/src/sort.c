/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:09:56 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:39:25 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_str(char **str, int i, int j)
{
	char *temp;

	temp = ft_strdup(str[i]);
	ft_strdel(&str[i]);
	str[i] = ft_strdup(str[j]);
	ft_strdel(&str[j]);
	str[j] = ft_strdup(temp);
	ft_strdel(&temp);
}

void	alpha_sort(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) > 0)
			{
				swap_str(str, i, j);
				i = -1;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	reverse(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i + 1] != NULL)
		i++;
	j = 0;
	while (j < i)
		swap_str(str, i--, j++);
}

void	sort_time(char **str, char *path, t_ls *ls)
{
	time_t	t1;
	time_t	t2;
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		j = i;
		t1 = get_time(str[i], path, ls);
		while (str[++j])
		{
			t2 = get_time(str[j], path, ls);
			if (t1 < t2 || (t1 == t2 && ft_strcmp(str[i], str[j]) > 0))
			{
				swap_str(str, i, j);
				i = -1;
				break ;
			}
		}
	}
}

void	sort_files(char **contents, char *path, t_ls *ls)
{
	if (ft_strchr(ls->flags, 't'))
		sort_time(contents, path, ls);
	if (ft_strchr(ls->flags, 'r'))
		reverse(contents);
}
