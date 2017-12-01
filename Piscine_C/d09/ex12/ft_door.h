/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:05:01 by bchan             #+#    #+#             */
/*   Updated: 2017/11/03 14:33:49 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# define CLOSE 0
# define TRUE 1
# define FALSE 0
# define OPEN 1
# define EXIT_SUCCESS 0

typedef int		t_bool;
typedef struct	s_door
{
	int	state;
}				t_door;
#endif
