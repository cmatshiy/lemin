/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:55:41 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 10:40:17 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	room_init(t_m *m, char *room_name, int start)
{
	int i;

	i = (start) ? -1 : 0;
	while (m->rooms[++i] && i < m->qt_rooms)
	{
		if (ft_strcmp(m->rooms[i], room_name) == 0)
			return (i);
	}
	return (i);
}
