/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 01:47:28 by aviau             #+#    #+#             */
/*   Updated: 2016/09/05 00:22:35 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	putname(char *name, char *mode, int col)
{
	char	*color;

	color = ft_strdup("\e[0m");
	if (col)
	{
		color = (mode[9] == 'x') ? "\e[31m" : color;
		color = (mode[0] == 'd') ? "\e[36m" : color;
		color = (mode[0] == 'l') ? "\e[35m" : color;
		color = (mode[0] == 's') ? "\e[32m" : color;
		color = (mode[0] == 'c') ? "\e[34;43m" : color;
	}
	ft_putstr(color);
	ft_putstr(name);
	ft_putstr("\e[0m");
}

void	display(t_files *file, t_param param)
{
	while (file)
	{
		ft_putstr(file->mode);
		ft_putchar(' ');
		ft_putnbr(file->nl);
		ft_putchar('\t');
		ft_putstr(file->usr);
		ft_putchar(' ');
		ft_putstr(file->grp);
		ft_putchar('\t');
		ft_putnbr(file->size);
	ft_putchar('\t');
		ft_putstr(file->time);
		ft_putchar(' ');
		putname(file->name, file->mode, param.color);
		ft_putchar('\n');
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
	f->time = get_time(&f->t, stat, param);
	f->next = NULL;
}

t_files	*list_files(char *path, t_param param)
{
	struct dirent	*dir;
	struct stat		stat;
	t_files			*f;
	t_files			*begin;
	char			*file;
	DIR				*dirp;

	if (!(dirp = opendir(path)))
		out_err(path);
	f = (t_files *)malloc(sizeof(t_files));
	begin = f;
	file = NULL;
	while ((dir = readdir(dirp)))
	{
		if (file)
		{
			f->next = (t_files *)malloc(sizeof(t_files));
			f = f->next;
		}
		file = set_path(path, dir->d_name);
		if ((lstat(file, &stat)) < 0)
			out_err("lstat");
		fill_stats(dir->d_name, stat, f, param);
	}
	ft_strdel(&file);
	sort(&begin, param);
	display(begin, param);
	closedir(dirp);
	return (begin);
}
