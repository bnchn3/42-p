/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:51:38 by bchan             #+#    #+#             */
/*   Updated: 2017/12/28 17:11:24 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_coor
{
	int				row;
	int				col;
}					t_coor;

void				free_four(char **tetri);
void				print_square(char *tetri);
char				*read_file(char *str);
int					tetcount(char *tetri);
int					check_file(char *tetri);
char				*copy_file(int fd, unsigned int buffer_size);
int					are_blocks_connected(char *tetri);
void				twod_memcpy(char **dest, char **src, t_coor *coor, char c);
t_coor				*create_coor(void);
t_coor				*set_coor(t_coor *coor, int x, int y);
int					check_place(char **dest, char **src, int x, int y);
void				place_tetri(char **dest, char **src, t_coor *coor, char c);
int					perm_dimen(char **test);
int					test_perm(char ***tetrimino, int *order, int dimen);
int					*create_order(int *order, int count);
void				swap(int *order, int i, int j);
int					*permute(char ***tetrimino, int *order, int start, int end);
void				final_print(char **final);
void				printer(char ***tetrimino, int *order, int count);
int					find_width(char **tetri);
int					max_width(char ***tetri);
int					find_length(char **tetri);
int					max_length(char ***tetri);
int					check_characters(char *file);
int					check_newlines(char *file);
int					check_line_count(char *file);
int					check_block_count(char *file);
int					check_width(char *file);
char				**create_test(int x, int y);
#endif
