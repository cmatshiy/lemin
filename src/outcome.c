/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:57:41 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 11:02:21 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		last_room(t_m *m, int i)
{
	if (m->table[i][m->qt_rooms - 1])
	{
		m->path[++(m->path_i)] = i;
		m->path[++(m->path_i)] = m->qt_rooms - 1;
		return (1);
	}
	return (0);
}

static void		element(t_m *m, int i, int path)
{
	m->table[m->curr_room][i] = 0;
	m->table[i][m->curr_room] = 0;
	if (path)
	{
		m->path[m->path_i] = -1;
		m->path_i--;
	}
}

static int		reach_door(t_m *m, int r_index, int d_index)
{
	while (d_index < m->qt_rooms)
	{
		if (m->table[r_index][++d_index] == 1)
			return (d_index);
	}
	return (0);
}

static int		in_path(t_m *m, int r_index)
{
	int i;

	i = -1;
	while (m->path[++i] != -1)
	{
		if (m->path[i] == r_index)
			return (1);
	}
	return (0);
}

int				outcome(t_m *m, int i)
{
	if (m->table[0][m->qt_rooms - 1])
	{
		m->path[++(m->path_i)] = m->qt_rooms - 1;
		return (1);
	}
	while ((i = reach_door(m, m->curr_room, i)))
	{
		if (last_room(m, i))
			return (1);
		else if (in_path(m, i))
			element(m, i, 0);
	}
	if ((m->curr_room = reach_door(m, m->curr_room, 0)) == 0)
	{
		if (m->path_i == 0 || m->curr_room == 0)
			return (0);
		m->curr_room = m->path[m->path_i - 1];
		element(m, m->path[m->path_i], 1);
		if (outcome(m, 0))
			return (1);
	}
	m->path[++(m->path_i)] = m->curr_room;
	if (outcome(m, 0))
		return (1);
	return (0);
}
