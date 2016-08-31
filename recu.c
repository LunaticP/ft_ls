/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:54:04 by aviau             #+#    #+#             */
/*   Updated: 2016/09/01 01:08:52 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*put_path(char *path, char *dir)
{
	path = ft_strjoin(path, dir);
	path = ft_strjoin(path, dir);
	return (path);
}

void	recu(t_param *param, char *path)
{
	char	**DIRS;
	int		d_num;

	d_num = 0;
	while (f->next)
	{
		if (f->mode[0] == 'd')
			d_num++;
		f = f->next;
	}
	DIRS = (char **)ft_memalloc(sizeof(char *) * (d_num - 1));
	f = go_first(f);
	d_num = 0;
	while (f->next)
	{
		if (ft_strcmp(f->name, ".") && ft_strcmp(f->name, ".."))
			if (f->mode[0] == 'd')
			{
				DIRS[d_num] = ft_strdup(f->name);
				d_num++;
			}
		f = f->next;
	}
	d_num = 0;
	while (DIRS[d_num])
	{
		path = ft_strjoin(path, DIRS[d_num]);
		ft_putstr(path);
		ft_putstr("/:\n");
		f = get_currdir(path, param);
		recu(f, param, path);
	}
	free(DIRS);
}
