/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:54:51 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/24 17:46:15 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ant(int ant, char *room)
{
	write(1, "L", 1);
	ft_putnbr(ant);
	write(1, "-", 1);
	ft_putstr(room);
	write(1, " ", 1);
}

static void		print_result(t_m *m, int n)
{
	int ants;

	if (n == (m->path_i + m->ants + 1))
		return ;
	ants = m->ants + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= m->path_i)
			ant(ants, m->rooms[m->path[n - ants]]);
	}
	write(1, "\n", 1);
	print_result(m, ++n);
}

void			result(t_m *m)
{
	int i;

	i = -1;
	ft_putendl(m->ants_str);
	ft_putendl(m->rooms_list);
	ft_putendl(m->links);
	write(1, "\n", 1);
	while (++i <= m->path_i)
	{
		write(1, "[", 1);
		ft_putnbr(m->path[i]);
		write(1, "]", 1);
		if (i != m->path_i)
			write(1, "-", 1);
	}
	write(1, "\n\n", 2);
	print_result(m, 2);
}
