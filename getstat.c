/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 01:27:42 by aviau             #+#    #+#             */
/*   Updated: 2016/09/04 06:53:48 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_mode(int mode)
{
	char	*out;
	char	buf[256];

	out = (char *)malloc(sizeof(char) * 12);
	out[0] = ((mode & S_IFMT) == S_IFDIR) ? 'd' : '-';
	out[0] = ((mode & S_IFMT) == S_IFLNK) ? 'l' : out[0];
	out[0] = ((mode & S_IFMT) == S_IFIFO) ? 'p' : out[0];
	out[0] = ((mode & S_IFMT) == S_IFCHR) ? 'c' : out[0];
	out[0] = ((mode & S_IFMT) == S_IFBLK) ? 'b' : out[0];
	out[0] = ((mode & S_IFMT) == S_IFSOCK) ? 's' : out[0];
	out[1] = (mode & S_IRUSR) ? 'r' : '-';
	out[2] = (mode & S_IWUSR) ? 'w' : '-';
	out[3] = (mode & S_IXUSR) ? 'x' : '-';
	out[4] = (mode & S_IRGRP) ? 'r' : '-';
	out[5] = (mode & S_IWGRP) ? 'w' : '-';
	out[6] = (mode & S_IXGRP) ? 'x' : '-';
	out[7] = (mode & S_IROTH) ? 'r' : '-';
	out[8] = (mode & S_IWOTH) ? 'w' : '-';
	out[9] = (mode & S_IXOTH) ? 'x' : '-';
	out[10] = ' ';
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

char	*parse_time(char *t)
{
	time_t	tloc;
	char	*out;

	out = ft_strnew(12);
	tloc = time(&tloc) / 36 / 24 / 36525 + 1970;
	if (!ft_strncmp(&t[20], ft_itoa(tloc), 4))
		out = ft_strncpy(out, &t[4], 12);
	else
		out = strncpy(out, &t[4], 7);
	out = ft_strjoin(out, &t[19]);
	out[12] = '\0';
	return (out);
}

char	*get_time(int *t, struct stat stat, t_param param)
{
	time_t	time;
	char	*out;


	if (param.date == 1)
		time = stat.st_atime;
	else if (param.date == 2)
		time = stat.st_birthtime;
	else
		time = stat.st_mtime;
	*t = time;
	out = parse_time(ctime(&time));
	return (out);
}
