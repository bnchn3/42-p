/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:43:17 by bchan             #+#    #+#             */
/*   Updated: 2017/11/12 13:42:30 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_H
# define EVALEXPR_H

char	**ft_split_whitespaces(char *str);

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;
#endif
