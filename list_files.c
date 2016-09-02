/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 01:47:28 by aviau             #+#    #+#             */
/*   Updated: 2016/09/02 03:00:15 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_files *file, t_param param)
{
	while (file->next)
	{
		if (file->last)
			file = file->next;
		ft_putstr(file->mode);
		ft_putchar('\t');
		ft_putnbr(file->nl);
		ft_putchar(' ');
		ft_putstr(file->usr);
		ft_putchar(' ');
		ft_putstr(file->grp);
		ft_putchar('\t');
		ft_putnbr(file->size);
		ft_putchar('\t');
		ft_putstr(file->name);
		ft_putchar('\n');
		if (!file->last)
			file = file->next;
	}
}

void	fill_stats(char *name, struct stat stat, t_files *f, t_param param)
{
	f->name = ft_strdup(name);
	f->mode = get_mode(stat.st_mode);
	f->nl = stat.st_nlink;
	f->usr = get_usr(stat.st_uid);
	f->grp = get_grp(stat.st_gid);
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
		if (file)
		{
			f->next = (t_files *)malloc(sizeof(t_files));
			f->next->last = f;
			f = f->next;
		}
		file = set_path(path, dir->d_name);
		if ((lstat(file, &stat)) < 0)
			out_err("lstat");
		fill_stats(dir->d_name, stat, f, param);
	}
	f = go_first(f);
	display(f, param);
	return (f);
}
