/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 01:47:28 by aviau             #+#    #+#             */
/*   Updated: 2016/09/01 08:08:59 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	out_err(char *str)
{
		perror(str);
		exit(1);
}

char	*set_path(char *path, char *name)
{
	char	*out;
	out = ft_strjoin(path, "/");
	out = ft_strjoin(path, name);
	return (out);
}

void	fill_stats(char *name, struct stat stat, t_files *f, t_param param)
{
	if (f->name)
	{
		f->next = (t_files *)malloc(sizeof(t_files));
		f->next->last = f;
		f = f->next;
		ft_putchar('.');
	}
	f->name = ft_strdup(name);
//	f->mode = get_mode(stat.mode);
	f->nl = stat.st_nlink;
//	f->usr = get_usr(stat.st_uid);
//	f->grp = get_grp(stat.st_gid);
	f->size = stat.st_size;
//	f->time = get_time(stat, param);
	f->next = NULL;
}

t_files	*list_files(char *path, t_param param)
{
	struct dirent	*dir;
	struct stat		stat;
	t_files			*f;
	char			*file;
	DIR				*dirp;

	if (!(dirp = opendir(path)))
		out_err(path);
	f = (t_files *)malloc(sizeof(t_files));
	f->last = NULL;
	while ((dir = readdir(dirp)))
	{
		file = set_path(path, dir->d_name);
		if ((lstat(file, &stat)) < 0)
			out_err("lstat");
		fill_stats(dir->d_name, stat, f, param);
	}
	f = go_first(f);
	while (f->next)
	{
		ft_putstr(f->name);
		ft_putchar('\t');
		ft_putnbr(f->nl);
		ft_putchar('\t');
		ft_putnbr(f->size);
		ft_putchar('\n');
		f = f->next;
	}
	return (f);
}
