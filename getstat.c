/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 01:27:42 by aviau             #+#    #+#             */
/*   Updated: 2016/09/02 02:56:14 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_mode(int mode)
{
	char *out;

	out = (char *)malloc(sizeof(char) * 12);
	out[0] = ((mode & S_IFMT) == S_IFDIR) ? 'd' : '-';
	out[0] = ((mode & S_IFMT) == S_IFLNK) ? 'l' : out[0];
	out[1] = (mode & S_IRUSR) ? 'r' : '-';
	out[2] = (mode & S_IWUSR) ? 'w' : '-';
	out[3] = (mode & S_IXUSR) ? 'x' : '-';
	out[4] = (mode & S_IRGRP) ? 'r' : '-';
	out[5] = (mode & S_IWGRP) ? 'w' : '-';
	out[6] = (mode & S_IXGRP) ? 'x' : '-';
	out[7] = (mode & S_IROTH) ? 'r' : '-';
	out[8] = (mode & S_IWOTH) ? 'w' : '-';
	out[9] = (mode & S_IXOTH) ? 'x' : '-';
	out[10] = '?';
	out[11] = '\0';
	return (out);
}

char	*get_usr(int uid)
{
	struct passwd	*usr;

	usr = getpwuid(uid);
	return (ft_strdup(usr->pw_name));
}

char	*get_grp(int gid)
{
	struct group	*grp;

	grp = getgrgid(gid);
	return (ft_strdup(grp->gr_name));
}

char	*get_time(struct stat stat, t_param param)
{
	return (NULL);
}
