/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 15:27:23 by aviau             #+#    #+#             */
/*   Updated: 2016/09/05 00:35:37 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h>

typedef struct	s_files
{
	char				*name;
	char				*mode;
	int					nl;
	char				*usr;
	char				*grp;
	int					size;
	char				*time;
	struct timespec		t;
	struct s_files		*next;
}				t_files;

typedef struct	s_param
{
	short	all;	// 1 all(a)   2 All without . & ..(A)
	short	list;	// 0 columns - 1 one column(1) - 2 details(l)
	short	sort;	// 1 time(t) - 2 size(S) 
	short	alph;	// 0 ascii - 1 none(f) 
	short	rev;	// 1 reverse(r)
	short	date;	// 0 modif - 1 access(u) - 2 creat(U)
	short	sign;	// 1 sign(F)
	short	color;	// 1 colorize(G)
	short	hread;	// 1 human readable(h)
	short	recu;	// 1 list recursivly(R)
}				t_param;

t_files	*list_files(char *path, t_param param);
void	recu(char *path, t_param param);
void	sort(t_files **f, t_param param);
void	out_err(char *str);
void	free_list(t_files **f);
char	*free_join(char *dst, char *src);
char	*set_path(char *path, char *name);
char	*get_mode(int mode);
char	*get_usr(int uid);
char	*get_grp(int gid);
char	*get_time(struct timespec *t, struct stat stat, t_param param);
int		is_hide(char c, int all);

#endif
