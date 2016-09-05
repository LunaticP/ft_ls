/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:54:04 by aviau             #+#    #+#             */
/*   Updated: 2016/09/05 00:44:59 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list(t_files **f)
{
	if (!*f)
		return;
	free_list(&(*f)->next);
	free((*f)->name);
	free((*f)->mode);
	free((*f)->usr);
	free((*f)->grp);
	free((*f)->time);
	free(*f);
	(*f)->name = NULL;
	(*f)->mode = NULL;
	(*f)->usr = NULL;
	(*f)->grp = NULL;
	(*f)->time = NULL;
	*f = NULL;
}

int		is_not(char *name)
{
	if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
		return (0);
	return (1);
}

void	recu(char *path, t_param p)
{
	t_files	*f;
	t_files	*cur;
	char	*dir;

	f = list_files(path, p);
	cur = f;
	while (f)
	{
		usleep(1000);
		if (f->mode[0] == 'd' && is_not(f->name) && is_hide(f->name[0], p.all))
		{
			dir = set_path(path, f->name);
			ft_putchar('\n');
			ft_putstr(dir);
			ft_putstr(":\n");
			recu(dir, p);
		}
		f = f->next;
	}
	f = cur;
	free_list(&f);
}
