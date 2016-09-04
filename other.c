/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 16:58:05 by aviau             #+#    #+#             */
/*   Updated: 2016/09/03 04:06:09 by aviau            ###   ########.fr       */
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
	out = ft_strjoin(out, name);
	return (out);
}

t_files	*go_first(t_files *f)
{
	while (f->last)
		f = f->last;
	return (f);
}
