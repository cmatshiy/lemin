/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:45:13 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/24 17:43:05 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		number(char **r, t_m *m, char *s)
{
	int index;

	index = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++index])
		{
			if (!ft_isdigit(s[index]))
				free_array(r, m, 1);
		}
	}
	else
		free_array(r, m, 1);
}

static void		valid_rooms(t_m *m, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, m, 1);
	number(r, m, r[1]);
	number(r, m, r[2]);
	free_array(r, m, 0);
}

void			rooms(t_m *m, char *line)
{
	m->started = 2;
	m->rooms_list = string_join(m->rooms_list, line, 0);
	if (line[0] == '#')
		return ;
	valid_rooms(m, line);
	m->qt_rooms++;
}
