/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 01:47:28 by aviau             #+#    #+#             */
/*   Updated: 2016/09/01 05:19:31 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	out_err(void)
{
		perror("ft_ls");
		exit(1);
}

char	*set_path(char *path, char *name)
{
	char	*out;
	out = ft_strjoin(path, "/");
	out = ft_strjoin(path, name);
	ft_putstr("path = \e[33m");
	ft_putstr(out);
	ft_putstr("\e[0m\n");
	return (out);
}

t_files	*list_files(char *path, t_param param)
{
	DIR				*dirp;
	struct dirent	*dir;
	struct stat		stat;
	char			*file;

	if (!(dirp = opendir(path)))
		out_err();
	while ((dir = readdir(dirp)))
	{
		file = set_path(path, dir->d_name);
		ft_putstr(dir->d_name);
		ft_putchar('\t');
		if ((lstat(file, &stat)) < 0)
			out_err();
		ft_putnbr(stat.st_nlink);
		ft_putchar('\n');
	}
	return (NULL);
}
