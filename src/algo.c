/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:43:45 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/27 10:28:33 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_empty(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

static t_m		*map_init_2(t_m *m)
{
	int i;
	int j;

	i = -1;
	m->init_2 = 1;
	m->path = (int*)ft_memalloc(sizeof(int) * 1000);
	m->table = (int**)ft_memalloc(sizeof(int*) * m->qt_rooms);
	m->rooms = (char**)ft_memalloc(sizeof(char*) * (m->qt_rooms + 1));
	while (++i < m->qt_rooms)
	{
		m->path[i] = -1;
		m->rooms[i] = NULL;
		m->table[i] = (int*)ft_memalloc(sizeof(int) * m->qt_rooms);
		j = -1;
		while (m->table[i][++j])
			m->table[i][j] = 0;
	}
	m->rooms[i] = NULL;
	m->path[0] = 0;
	return (m);
}

static void		read_map(t_m *m)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (m->ants == 0)
			count_ants(m, line);
		else if (ft_strchr(line, '-') || m->started == 3)
			links(m, line);
		else if ((m->started == 1 || m->started == 2) && !is_empty(line))
			rooms(m, line);
		else
			exit_function(m, 1);
	}
	if (!m->ants || !m->links[0])
		exit_function(m, 1);
	m = map_init_2(m);
}

static t_m		*map_init(void)
{
	t_m *m;

	m = (t_m*)ft_memalloc(sizeof(t_m));
	m->links = ft_strnew(1);
	m->ants_str = ft_strnew(1);
	m->rooms_list = ft_strnew(1);
	m->qt_rooms = 0;
	m->ants = 0;
	m->started = 0;
	m->curr_room = 0;
	m->path_i = 0;
	m->init_2 = 0;
	m->good[0] = 0;
	m->good[1] = 0;
	m->rooms = NULL;
	m->table = NULL;
	m->path = NULL;
	return (m);
}

int				main(void)
{
	t_m *m;

	m = map_init();
	read_map(m);
	add_rooms(m);
	if (!m->good[0] || !m->good[1])
		exit_function(m, 1);
	create_table(m);
	print_grid_like(m);
	if (outcome(m, 0))
		result(m);
	else
		exit_function(m, 1);
	exit_function(m, 0);
}
