/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 12:54:42 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 13:10:33 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ck_start_end(t_m *m, char **r, int end)
{
	if (end)
	{
		m->rooms[m->qt_rooms - 1] = ft_strdup(r[0]);
		(m->good[1])++;
		return ;
	}
	m->rooms[0] = ft_strdup(r[0]);
	(m->good[0])++;
}

static void		good(t_m *m, char **line, char **r, int end)
{
	if (++(m->good[end]) > 1)
	{
		free_array(r, m, 0);
		free_array(line, m, 1);
	}
}

static void		is_valid(t_m *m, int i, char **r)
{
	int r_index;

	r_index = room_init(m, r[0], 0);
	if (r_index > 0 && i != r_index)
		exit_function(m, 1);
	m->rooms[i] = ft_strdup(r[0]);
}

void			add_rooms(t_m *m)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	line = ft_strsplit(m->rooms_list, '\n');
	while (line[++i] && j < m->qt_rooms)
	{
		r = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
			good(m, line, r, 0);
		else if (!ft_strcmp("##end", line[i]))
			good(m, line, r, 1);
		else if (m->good[0] == 1 && line[i][0] != '#')
			ck_start_end(m, r, 0);
		else if (m->good[1] == 1 && line[i][0] != '#')
			ck_start_end(m, r, 1);
		else if (line[i][0] != '#')
			is_valid(m, j++, r);
		free_array(r, m, 0);
	}
	free_array(line, m, 0);
}
