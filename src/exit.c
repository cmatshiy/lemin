/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:41:41 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 10:15:12 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_function(t_m *m, int error)
{
	int i;

	free(m->links);
	free(m->ants_str);
	free(m->rooms_list);
	if (m->init_2)
	{
		free(m->path);
		free_array(m->rooms, m, 0);
		i = -1;
		while (++i < m->qt_rooms)
			free(m->table[i]);
		free(m->table);
	}
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}
