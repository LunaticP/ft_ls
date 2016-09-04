/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 04:08:04 by aviau             #+#    #+#             */
/*   Updated: 2016/09/04 06:58:28 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files	*sort_ascii(t_files *f)
{
	int	changed;

	changed = 1;
	while (changed && !(changed = 0))
	{
		f = go_first(f);
		while (f->next)
		{
			if (ft_strcmp(f->name, f->next->name) > 0 && (changed = 1))
			{
				f->next->last = f->last;
				if (f->last)
					f->last->next = f->next;
				if (f->next->next)
					f->next->next->last = f;
				f->last = f->next;
				f->next = f->next->next;
				f->last->next = f;
			}
			if (f->next)
				f = f->next;
		}
	}
	f = go_first(f);
	return (f);
}

t_files	*sort_size(t_files *f)
{
	int	changed;

	changed = 1;
	while (changed && !(changed = 0))
	{
		f = go_first(f);
		while (f->next)
		{
			if ((f->size < f->next->size) && (changed = 1))
			{
				f->next->last = f->last;
				if (f->last)
					f->last->next = f->next;
				if (f->next->next)
					f->next->next->last = f;
				f->last = f->next;
				f->next = f->next->next;
				f->last->next = f;
			}
			if (f->next)
				f = f->next;
		}
	}
	f = go_first(f);
	return (f);
}

t_files	*sort_time(t_files *f)
{
	int		changed;

	changed = 1;
	while (changed && !(changed = 0))
	{
		f = go_first(f);
		while (f->next)
		{
			if ((f->t < f->next->t) && (changed = 1))
			{
				f->next->last = f->last;
				if (f->last)
					f->last->next = f->next;
				if (f->next->next)
					f->next->next->last = f;
				f->last = f->next;
				f->next = f->next->next;
				f->last->next = f;
			}
			if (f->next)
				f = f->next;
		}
	}
	f = go_first(f);
	return (f);
}

t_files	*sort(t_files *f, t_param param)
{
	if (!param.alph)
		f = sort_ascii(f);
	if (param.sort == 1)
		f = sort_time(f);
	if (param.sort == 2)
		f = sort_size(f);
//	if (param.rev)
//		f = sort_rev(f);
	return (f);
}
