/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 04:08:04 by aviau             #+#    #+#             */
/*   Updated: 2016/09/04 21:49:04 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	reverse(char *tmp1, int tmp2, struct timespec tmp3, t_files **f)
{
	tmp1 = (*f)->name;
	(*f)->name = (*f)->next->name;
	(*f)->next->name = tmp1;
	tmp1 = (*f)->mode;
	(*f)->mode = (*f)->next->mode;
	(*f)->next->mode = tmp1;
	tmp2 = (*f)->nl;
	(*f)->nl = (*f)->next->nl;
	(*f)->next->nl = tmp2;
	tmp1 = (*f)->usr;
	(*f)->usr = (*f)->next->usr;
	(*f)->next->usr = tmp1;
	tmp1 = (*f)->grp;
	(*f)->grp = (*f)->next->grp;
	(*f)->next->grp = tmp1;
	tmp2 = (*f)->size;
	(*f)->size = (*f)->next->size;
	(*f)->next->size = tmp2;
	tmp1 = (*f)->time;
	(*f)->time = (*f)->next->time;
	(*f)->next->time = tmp1;
	tmp3 = (*f)->t;
	(*f)->t = (*f)->next->t;
	(*f)->next->t = tmp3;
}

void	sort_ascii(t_files **f)
{
	t_files			**begin;
	char			*tmp1;
	int				tmp2;
	struct timespec	tmp3;

	begin = f;
	while ((*f)->next)
	{
		if (ft_strcmp((*f)->name, (*f)->next->name) > 0)
		{
			reverse(tmp1, tmp2, tmp3, f);
			f = begin;
		}
		else
			f = &(*f)->next;
	}
}

void	sort_time(t_files **f)
{
	t_files			**begin;
	char			*tmp1;
	int				tmp2;
	struct timespec	tmp3;

	begin = f;
	while ((*f)->next)
	{
		if ((*f)->t.tv_sec < (*f)->next->t.tv_sec)
		{
			reverse(tmp1, tmp2, tmp3, f);
			f = begin;
		}
		else if ((*f)->t.tv_sec == (*f)->next->t.tv_sec)
		{
			if ((*f)->t.tv_nsec < (*f)->next->t.tv_nsec)
			{
				reverse(tmp1, tmp2, tmp3, f);
				f = begin;
			}
			else
				f = &(*f)->next;
		}
		else
			f = &(*f)->next;
	}
}

void	sort_size(t_files **f)
{
	t_files			**begin;
	char			*tmp1;
	int				tmp2;
	struct timespec	tmp3;

	begin = f;
	while ((*f)->next)
	{
		if ((*f)->size < (*f)->next->size)
		{
			reverse(tmp1, tmp2, tmp3, f);
			f = begin;
		}
		else
			f = &(*f)->next;
	}
}

void	sort(t_files **f, t_param param)
{
	if (!param.alph)
		sort_ascii(f);
	if (param.sort == 1)
		sort_time(f);
	else if (param.sort == 2)
		sort_size(f);
}
