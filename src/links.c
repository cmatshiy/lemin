/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:03:03 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/24 17:31:06 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	links(t_m *m, char *line)
{
	if (m->started == 2)
		m->started = 3;
	if (m->started != 3)
		exit_function(m, 1);
	m->links = string_join(m->links, line, 0);
}
