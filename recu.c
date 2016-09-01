/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:54:04 by aviau             #+#    #+#             */
/*   Updated: 2016/09/01 08:10:54 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recu(char *path, t_param param)
{
	t_files	*f;

	f = list_files(path, param);
	f = go_first(f);
	while (f->next)
	{
		if (f->mode[0] == 'd')
		{
			ft_putstr("\e[32m.");
			path = set_path(path, f->name);
			ft_putstr(path);
			ft_putstr(":\n");
			recu(path, param);
		}
		ft_putstr("\e[31m.");	
	}
}
