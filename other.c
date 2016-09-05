/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 16:58:05 by aviau             #+#    #+#             */
/*   Updated: 2016/09/05 00:47:30 by aviau            ###   ########.fr       */
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
	out = free_join(out, name);
	return (out);
}

int		is_hide(char c, int all)
{
	if (all || c != '.')
		return (1);
	return (0);
}

char	*free_join(char *dst, char *src)
{
	char	*tmp;

	tmp = dst;
	dst = ft_strjoin(dst, src);
	free(tmp);
	return (dst);
}
