/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:19:03 by bchan             #+#    #+#             */
/*   Updated: 2017/11/15 13:53:05 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

typedef struct		s_coor
{
	int				coor[2];
	int				dimen;
}					t_coor;

char				**ft_split_whitespaces(char *str);
char				*copy_file(int fd, unsigned int buffer_size);
t_list				*create_new_elem(void);
t_list				*read_files(char *str);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					check_obstacle(char **str, int y, int x);
int					check_map(char **str);

#endif
