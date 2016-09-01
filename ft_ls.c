/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 20:10:39 by aviau             #+#    #+#             */
/*   Updated: 2016/09/01 06:33:29 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		valid(char c)
{
	static char	*valid = "AFGRSUalhrtu1";
	int			i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (0);
		i++;
	}
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [AFGRSUalhrtu1] [file ...]\n");
	return (1);
}

void	set_param(char p, t_param *param)
{
	param->all = (p == 'a') ? 1 : param->all;
	param->all = (p == 'A') ? 2 : param->all;
	param->list = (p == '1') ? 1 : param->list;
	param->list = (p == 'l') ? 2 : param->list;
	param->sort = (p == 't') ? 1 : param->sort;
	param->sort = (p == 'S') ? 1 : param->sort;
	param->rev = (p == 'r') ? 1 : param->rev;
	param->date = (p == 'u') ? 1 : param->date;
	param->date = (p == 'U') ? 2 : param->date;
	param->sign = (p == 'F') ? 1 : param->sign;
	param->color = (p == 'g') ? 1 : param->color;
	param->hread = (p == 'h') ? 1 : param->hread;
	param->recu = (p == 'R') ? 1 : param->recu;
}

int		parse_param(char **av, t_param *param)
{
	int i;
	int j;

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (valid(av[i][j]))
				return (0);
			else
				set_param(av[i][j], param);
			j++;
		}
		i++;
	}
	return (i);
}

int		main(int ac, char **av)
{
	t_param	param;
	int		i;

	if (ac == 1)
		list_files("./", param);
	else if (!(i = parse_param(av, &param)))
		return (1);
	else if (av[i])
		while (av[i])
		{
			if (param.recu)
				recu(av[i], param);
			else
				list_files(av[i], param);
			i++;
		}
	else
		if (param.recu)
			recu("./", param);
		else
			list_files("./", param);
	return (0);
}
