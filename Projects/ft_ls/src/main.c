/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:07:10 by bchan             #+#    #+#             */
/*   Updated: 2018/04/16 15:07:14 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ft_intlen(uintmax_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	while (n != 0)
	{
		n /= (unsigned int)10;
		len++;
	}
	return (len);
}

void	del_passwd(struct **passwd)
{
	if (passwd)
	{
		if (*passwd)
		{
			ft_strdel(&(*(passwd)->pw_name));
			ft_strdel(&(*(passwd)->pw_passwd));
			ft_strdel(&(*(passwd)->pw_class));
			ft_strdel(&(*(passwd)->pw_gecos));
			ft_strdel(&(*(passwd)->pw_dir));
			ft_strdel(&(*(passwd)->pw_shell));
			free(*passwd);
		}
		*passwd = NULL;
	}
}

void	del_group(struct **group)
{
	int i;

	i = 0;
	if (group)
	{
		if (*group)
		{
			ft_strdel(&(*(group)->gr_name));
			ft_strdel(&(*(group)->gr_passwd));
			while (*(group)->gr_mem[i])
			{
				ft_strdel(&(*(group)->gr_name));
				i++;
			}
			ft_memdel((void **)&(*(group)->gr_mem));
			free(*group);
		}
		*group = NULL;
	}
}

t_ls	*parse_flags(int argc, char **argv, t_ls *ls)
{
	int i;
	int j;

	i = 0;
	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->flags = ft_strnew(0);
	while (argv[++i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 'l' && argv[i][j] != 'R' && argv[i][j] != 'a' &&
				argv[i][j] != 'r' && argv[i][j] != 't')
			{
				ft_putstr_fd("ft_ls: illegal option -- ", 2);
				ft_putchar_fd(argv[i][j], 2);
				ft_putchar_fd('\n', 2);
				ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
				exit(EXIT_FAILURE);
			}
			ft_strpchar(&(ls->flags), argv[i][j++]);
		}
	}
	return (ls);
}

int	is_file(char *str)
{
	struct stat	*buf;
	int		result;

	buf = (struct stat *)malloc(sizeof(struct stat));
	if (stat(str, buf) == 0)
	{
		if (buf->st_mode & S_IFDIR)
			result = 0;
		else
			result = 1;
	}
	else
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	ft_memdel((void **)&buf);
	return (result);
}

void	parse_args(int argc, char **argv, t_ls *ls)
{
	int	i;

	i = 1;
	ls->num_dir = 0;
	ls->num_files = 0;
	while (i < argc)
		if (argv[i][0] == '-')
			i++;
	ls->dirs = (char **)malloc(sizeof(char *) * (argc - i + 1));
	ls->files = (char **)malloc(sizeof(char *) * (argc - i + 1));
	while (i < argc)
	{
		if (is_file(argv[i]))
			ls->files[ls->num_files++] = ft_strdup(argv[i]);
		else
		 	ls->dirs[ls->num_dir++] = ft_strdup(argv[i]);
		i++;
	}
	ls->files[ls->num_files] = NULL;
	ls->dirs[ls->num_dir] = NULL;
}

void	swap_str(char *s1, char *s2);
{
	char *temp;

	temp = ft_strdup(s1);
	ft_strdel(&s1);
	s1 = ft_strdup(s2);
	ft_strdel(&s2);
	s2 = ft_strdup(temp);
}

void 	alpha_sort(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) > 0)
			{
				swap_str(str[i], str[j]);
				i = 0;
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
		swap_str(str[j++], str[i--]);
}

time_t	get_time(char *str)
{
	time_t t;
	struct stat		*buf;

	buf = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(str, buf) == 0)
		t = buf->st_mtimespec->tv_sec;
	else
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
	ft_memdel((void **)&buf);
	return (t);
}

void	sort_time(char **str)
{
	time_t	time1;
	time_t	time2;
	int i;
	int j;

	i = -1;
	while (str[++i])
	{
		j = i;
		time1 = get_time(str[i]);
		while (str[++j])
		{
			time2 = get_time(str[j]);
			if (time1 < time2 || (time1 == time2 && ft_strcmp(str[i], str[j]) > 0))
			{
				swap_str(str[i], str[j]);
				i = 0;
				break ;
			}
		}
	}
}

void	sort_files(t_ls *ls)
{
	if (ft_strchr(ls->flags, 'r') && ft_strchr(ls->flags, 't'))
	{
		sort_time(ls->files);
		reverse(ls->files);
	}
	else if (ft_strchr(ls->flags, 'r'))
		reverse(ls->files);
	else if (ft_strchr(ls->flags, 't'))
		sort_time(ls->files);
}

void	get_name(char *path, struct stat *buf, t_ls *ls)
{
	char	buf2[PATH_MAX];
	ssize_t	len;

	ft_putstr(path);
	if (buf->st_mode & S_IFLNK)
	{
		ft_putstr(" -> ");
		len = readlink(path, buf2, sizeof(buf2) - 1));
		if (len != -1)
		{
			buf2[len] = '\0';
			ft_putstr(buf2);
		}
		else
		{
			perror("readlink");
			exit(EXIT_FAILURE);
		}
	}
	ft_putchar('\n');
}

void 	get_year(time_t *t, char *temp, struct timeval *tp, int i)
{
	if (*t - tp->tv_sec > 15778800 || tp->tv_sec - *t > 15778800)
	{
		i = 20;
		while (i < 25)
			ft_putchar(temp[i++]);
	}
	else
		while (i < 18)
			ft_putchar(temp[i++]);
	ft_memdel((void **)&t);
	ft_memdel((void **)&tp);
	ft_strdel(&temp);
}

void	get_time_long(char *path, struct stat *buf, t_ls *ls)
{
	time_t *t;
	char	*temp;
	struct timeval *tp;
	int		i;

	t = (time_t *)malloc(sizeof(time_t));
	tp = (struct timeval *)malloc(sizeof(struct timeval));
	*t = buf->st_mtimespec->tv_sec;
	temp = ctime(time(t));
	i = 5;
	while (i < 12)
		ft_putchar(temp[i++]);
	gettimeofday(tp, NULL);
	get_year(t, temp, tp, i);
	get_name(path, buf, ls);
}

void 	get_size(char *path, struct stat *buf, t_ls *ls)
{
	int	pad;

	pad = ls->size_pad - ft_intlen(buf->st_size);
	while (pad)
	{
		ft_putchar(' ');
		pad--;
	}
	ft_putnbr(buf->st_size);
	ft_putchar(' ');
	get_time_long(path, buf, ls);
}

void	get_group(char *path, struct stat *buf, t_ls *ls)
{
	int		pad;
	struct	*group;

	group = getgrgid(buf->st_gid);
	if (group)
	{
		pad = ls->group_pad - ft_strlen(group->gr_name);
		while (pad)
		{
			ft_putchar(' ');
			pad--;
		}
		ft_putstr(group->gr_name);
		ft_putstr("  ");
		del_group(group);
	}
	else
	{
		perror("getgrgid");
		exit(EXIT_FAILURE);
	}
	get_size(path, buf, ls);
}

void	get_user(char *path, struct stat *buf, t_ls *ls)
{
	int 	pad;
	struct	*passwd;

	passwd = getpwuid(buf->st_uid)
	if (passwd)
	{
		pad = ls->user_pad - ft_strlen(passwd->pw_name);
		while (pad)
		{
			ft_putchar(' ');
			pad--;
		}
		ft_putstr(passwd->pw_name);
		ft_putstr("  ");
		del_passwd(passwd);
	}
	else
	{
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
	get_group(path, buf, ls);
}

void	get_links(char *path, struct stat *buf, t_ls *ls)
{
	int pad;

	pad = ls->link_pad - ft_intlen(st_nlink);
	while (pad)
	{
		ft_putchar(' ');
		pad--;
	}
	ft_putnbr(st_nlink);
	ft_putchar(' ');
	get_user(path, buf, ls);
}

void	get_ext_attr(char *path, struct stat *buf, t_ls *ls)
{
	acl_t	acl;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW))
		ft_putchar('@');
	else if ((acl = acl_get_file(path, ACL_TYPE_ACCESS)))
	{
		if (acl_valid(acl) == 0)
			ft_putchar('+');
		acl_free(acl);
	}
	else
		ft_putchar(' ');
	ft_putchar(' ');
	get_links(path, buf, ls);
}

void	get_other_per(char *path, struct stat *buf, t_ls *ls)
{
	if (buf->st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (buf->st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf->st_mode & S_IXOTH) && (buf->st_mode & S_ISVTX))
		ft_putchar('t');
	else if (buf->st_mode & S_ISVTX)
		ft_putchar('T');
	else if (buf->st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
	get_ext_attr(path, buf, ls);
}

void	get_group_per(char *path, struct stat *buf, t_ls *ls)
{
	if (buf->st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (buf->st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf->st_mode & S_IXGRP) && (buf->st_mode & S_ISGID))
		ft_putchar('s');
	else if (buf->st_mode & S_ISGID)
		ft_putchar('S');
	else if (buf->st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	get_other_per(path, buf, ls);
}

void	get_user_per(char *path, struct stat *buf, t_ls *ls)
{
	if (buf->st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (buf->st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf->st_mode & S_IXUSR) && (buf->st_mode & S_ISUID))
		ft_putchar('s');
	else if (buf->st_mode & S_ISUID)
		ft_putchar('S');
	else if (buf->st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	get_group_per(path, buf, ls);
}

void 	get_mode(char *path, struct stat *buf, t_ls *ls)
{
	if (buf->st_mode & S_IFBLK)
		ft_putchar('b');
	else if (buf->st_mode & S_IFCHR)
		ft_putchar('c');
	else if (buf->st_mode & S_IFDIR)
		ft_putchar('d');
	else if (buf->st_mode & S_IFLNK)
		ft_putchar('l');
	else if (buf->st_mode & S_IFSOCK)
		ft_putchar('s');
	else if (buf->st_mode & S_IFIFO)
		ft_putchar('p');
	else if (buf->st_mode & S_IFREG)
		ft_putchar('-');
	get_user_per(path, buf, ls);
}

void	reset_pads(t_ls *ls)
{
	ls->link_pad = 0;
	ls->user_pad = 0;
	ls->group_pad = 0;
	ls->size_pad = 0;
}

void	get_user_pad(t_ls *ls, struct stat *buf)
{
	struct *passwd;

	passwd = getpwuid(buf->st_uid);
	if (passwd)
	{
		if (ft_strlen(passwd->pw_name) > ls->user_pad)
			ls->user_pad = ft_strlen(passwd->pw_name);
		del_passwd(&passwd);
	}
	else
	{
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
}

void	get_group_pad(t_ls *ls, struct stat *buf)
{
	struct *group;

	group = getgrgid(buf->st_gid);
	if (group)
	{
		if (ft_strlen(group->gr_name) > ls->group_pad)
			ls->group_pad = ft_strlen(group->gr_name);
		del_group(&group);
	}
	else
	{
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
}

void	get_pads(t_ls *ls, int count, char **str)
{
	struct stat *buf;
	int		i;

	reset_pads(ls);
	i = 0;
	buf = (struct stat *)malloc(sizeof(struct stat));
	while (i < count)
	{
		if (lstat(str[i++], buf) == 0)
		{
			if (ft_intlen(st_nlink) > ls->link_pad)
				ls->link_pad = ft_intlen(st_nlink);
			if (ft_intlen(st_size) > ls->size_pad)
				ls->size_pad = ft_intlen(st_size);
			get_user_pad(ls, buf);
			get_group_pad(ls, buf);
		}
		else
		{
			perror("lstat");
			exit(EXIT_FAILURE);
		}
	}
	ft_memdel((void **)&buf);
}

void	print_files_long(t_ls *ls)
{
	struct stat *buf;
	int		i;

	i = 0;
	get_pads(ls, ls->num_files, ls->files);
	buf = (struct stat *)malloc(sizeof(struct stat));
	while(i < ls->num_files)
	{
		if (lstat(ls->files[i], buf) == 0)
			get_mode(ls->files[i], buf, ls);
		else
		{
			perror("stat");
			exit(EXIT_FAILURE);
		}
	}
	ft_memdel((void **)&buf);
}

void	print_files(t_ls *ls)
{
	int	i;

	alpha_sort(ls->files);
	if (ft_strchr(ls->flags, 'r') || ft_strchr(ls->flags, 't')
		sort_files(ls);
	if (ft_strchr(ls->flags, 'l'))
		print_files_long(ls);
	else
	{
		i = 0;
		while (i < ls->num_files)
			ft_putendl(ls->files[i]);
		i++;
	}
	if (ls->num_dir > 0)
		ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	t_ls	*ls;

	ls = parse_flags(argc, argv, ls);
	parse_args(argc, argv, ls);
	if (ls->num_files > 0)
		print_files(ls);
	return (0);
}
