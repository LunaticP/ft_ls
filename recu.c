/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:54:04 by aviau             #+#    #+#             */
/*   Updated: 2016/09/04 02:11:09 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list(t_files *f)
{
	t_files	*tmp;

	while (f->next)
	{
		tmp = f->next;
		free(f->name);
		free(f->mode);
		free(f->usr);
		free(f->grp);
		free(f);
		f = tmp;
	}
}

int		is_not(char *name)
{
	if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
		return (0);
	return (1);
}

void	recu(char *path, t_param param)
{
	t_files	*f;
	t_files	*cur;

	f = list_files(path, param);
	f = go_first(f);
	cur = f;
	while (f)
	{
		usleep(1000);
		ft_putstr("\e[33m");
		ft_putstr(f->name);
		ft_putstr("\t\e[32mtest1\e[0m\n");
		if (f->mode[0] == 'd' && is_not(f->name))
		{
			ft_putstr("\e[33mtest2\e[0m\n");
			path = set_path(path, f->name);
			ft_putstr(path);
			ft_putstr(":\n");
			recu(path, param);
		}
		f = f->next;
	}
	f = cur;
	free_list(f);
}
