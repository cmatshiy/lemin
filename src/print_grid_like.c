/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid_like.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:54:01 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/27 10:09:48 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		header(t_m *m)
{
	int i;

	i = -1;
	write(1, "\n\n", 2);
	write(1, "\t   ", 4);
	while (++i < m->qt_rooms)
	{
		write(1, " ", 1);
		ft_putnbr((i > 9) ? (i % 10) : i);
	}
	write(1, "\n\n", 2);
}

void			print_grid_like(t_m *m)
{
	int i;
	int j;

	header(m);
	i = -1;
	while (++i < m->qt_rooms)
	{
		write(1, "\t", 1);
		ft_putnbr((i > 9) ? (i % 10) : i);
		write(1, "   ", 3);
		j = -1;
		while (++j < m->qt_rooms)
		{
			ft_putnbr(m->table[i][j]);
			write(1, " ", 1);
		}
		write(1, "\t\t", 2);
		write(1, "[", 1);
		ft_putnbr(i);
		write(1, "] -  ", 5);
		ft_putendl(m->rooms[i]);
	}
	write(1, "\n\n", 2);
}
