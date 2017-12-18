/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:51:38 by bchan             #+#    #+#             */
/*   Updated: 2017/12/16 11:23:24 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_coor
{
	int				*row;
	int				*col;
}					t_coor;

char				*read_file(char *str);
int					tetcount(char *tetri);
int					check_file(char *tetri);
void				free_four(char **four_by_four)
int					are_blocks_connected(char *tetri);
#endif
