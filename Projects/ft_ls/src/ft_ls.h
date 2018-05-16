/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:07:26 by bchan             #+#    #+#             */
/*   Updated: 2018/04/16 15:07:27 by bchan            ###   ########.fr       */
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

typedef struct	s_ls
{
	char	*flags;
	char	**dirs;
	char	**files;
	int		num_dir;
	int		num_files;
	int		link_pad;
	int		user_pad;
	int		group_pad;
	int		size_pad;
	int		first;
}				t_ls;

#endif
