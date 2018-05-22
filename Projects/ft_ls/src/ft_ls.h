/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:07:26 by bchan             #+#    #+#             */
/*   Updated: 2018/05/21 12:33:32 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>
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
time_t			get_time(char *str, char *path, t_ls *ls);
char			**copy_2d(char **contents);
char			**read_dir(char *path, t_ls *ls);
int				is_file(char *str);
int				get_col_pad(char **contents);
t_ls			*parse_flags(char **argv);
void			flag_error(char c);
void			check_dir(DIR *dir, char *path);
void			parse_args(int argc, char **argv, t_ls *ls);
void			swap_str(char **str, int i, int j);
void			alpha_sort(char **str);
void			reverse(char **str);
void			sort_time(char **str, char *path, t_ls *ls);
void			sort_files(char **contents, char *path, t_ls *ls);
void			sort_dir(t_ls *ls);
void			reset_pads(t_ls *ls);
void			get_user_pad(t_ls *ls, struct stat *buf);
void			get_group_pad(t_ls *ls, struct stat *buf);
void			get_pads(t_ls *ls, char **str, char *path, struct stat *buf);
void			get_mode(char *path, struct stat *buf, t_ls *ls);
void			get_user_per(char *path, struct stat *buf, t_ls *ls);
void			get_group_per(char *path, struct stat *buf, t_ls *ls);
void			get_other_per(char *path, struct stat *buf, t_ls *ls);
void			get_ext_attr(char *path, struct stat *buf, t_ls *ls);
void			get_links(char *path, struct stat *buf, t_ls *ls);
void			get_user(char *path, struct stat *buf, t_ls *ls);
void			get_group(char *path, struct stat *buf, t_ls *ls);
void			get_size(char *path, struct stat *buf, t_ls *ls);
void			get_time_long(char *path, t_ls *ls);
void			get_year(time_t t, char *temp, time_t *t2, int i);
void			get_name(char *abs_path, char *path, struct stat *buf,
					t_ls *ls);
void			print_xattr(char *path, t_ls *ls);
void			print_xattr_2(char *path, t_ls *ls, char *namebuf, ssize_t max);
void			print_acl(char *path, t_ls *ls);
void			get_col(char **contents);
void			print_col(char **contents, int col, int pad);
void			print_files_long(t_ls *ls);
void			print_files(t_ls *ls);
void			get_dir_size(char **contents, char *path, struct stat *buf);
void			get_sub(char **contents, char *path, char **sub);
void			print_dir_long(char **contents, char *path, char **sub,
					t_ls *ls);
void			print_dir(char **contents, char *path, char **sub, t_ls *ls);
void			print_rec(t_ls *ls, char **sub);
void			list_dir(char **path, t_ls *ls);
void			char_del(char **str);
void			ls_del(t_ls *ls);

#endif
