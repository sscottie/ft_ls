/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:45:50 by sscottie          #+#    #+#             */
/*   Updated: 2020/03/03 12:39:47 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "ft_printf.h"
# include <dirent.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <stdio.h>
         
typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;


// typedef struct	s_dirent
// {
//   ino_t          d_ino;       /* inode number */
//   off_t          d_off;       /* offset to the next dirent */
//   unsigned short d_reclen;    /* length of this record */
//   unsigned char  d_type;      /* type of file; not supported
//                                  by all file system types */
//   char           d_name[256]; /* filename */
// };

#endif