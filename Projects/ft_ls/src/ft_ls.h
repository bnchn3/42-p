/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:07:26 by bchan             #+#    #+#             */
/*   Updated: 2018/05/16 17:41:10 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <sys/acl.h>
# include <grp.h>
# include <fcntl.h>

typedef struct	s_ls
{
	char		*flags;
	char		**dirs;
	char		**files;
	int			num_dir;
	int			num_files;
	int			link_pad;
	int			user_pad;
	int			group_pad;
	int			size_pad;
	int			first;
}				t_ls;

size_t			ft_intlen(uintmax_t n);
time_t			get_time(char *str);
char			**copy_2d(char **contents);
char			**read_dir(char *path, t_ls *ls);
int				is_file(char *str);
t_ls			*parse_flags(char **argv);
void			parse_args(int argc, char **argv, t_ls *ls);
void			swap_str(char **str, int i, int j);
void			alpha_sort(char **str);
void			reverse(char **str);
void			sort_time(char **str);
void			sort_files(char **contents, t_ls *ls);
void			reset_pads(t_ls *ls);
void			get_user_pad(t_ls *ls, struct stat *buf);
void			get_group_pad(t_ls *ls, struct stat *buf);
void			get_pads(t_ls *ls, char **str, char *path, struct stat *buf);
void			get_mode(char *path, struct stat *buf, t_ls *ls);
void			get_user_per(char *path, struct stat *buf, t_ls *ls);
void			get_group_per(char *path, struct stat *buf, t_ls *ls);
void			get_other_per(char *path, struct stat *buf, t_ls *ls);
void			get_ext_attr(char *path, struct stat *buf, t_ls *ls);
void			get_links(struct stat *buf, t_ls *ls);
void			get_user(struct stat *buf, t_ls *ls);
void			get_group(struct stat *buf, t_ls *ls);
void			get_size(struct stat *buf, t_ls *ls);
void			get_time_long(struct stat *buf);
void			get_year(time_t *t, char *temp, time_t *t2, int i);
void			get_name(char *path, struct stat *buf);
void			print_files_long(t_ls *ls);
void			print_files(t_ls *ls);
void			get_dir_size(char **contents, char *path, struct stat *buf);
void			print_dir_long(char **contents, char *path, char **sub,
					t_ls *ls);
void			print_dir(char **contents, char *path, char **sub);
void			print_rec(t_ls *ls, char **sub);
void			list_dir(char **path, t_ls *ls);
void			char_del(char **str);
void			ls_del(t_ls *ls);

#endif
