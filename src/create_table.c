/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:27:23 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 10:22:37 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		valid_link(t_m *m, char *link)
{
	char **i;

	i = ft_strsplit(link, '-');
	if (i[2] != NULL)
		free_array(i, m, 1);
	free_array(i, m, 0);
}

void			create_table(t_m *m)
{
	int		i;
	int		r1;
	int		r2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(m->links, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		valid_link(m, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r1 = room_init(m, l[0], 1)) >= m->qt_rooms ||
				(r2 = room_init(m, l[1], 1)) >= m->qt_rooms)
		{
			free_array(l, m, 0);
			free_array(links, m, 1);
		}
		(r2) ? (m->table[r1][r2] = 1) : 0;
		(r1) ? (m->table[r2][r1] = 1) : 0;
		free_array(l, m, 0);
	}
	free_array(links, m, 0);
}
