/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:21:10 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/24 17:23:46 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_ants(t_m *m, char *line)
{
	int		i;
	char	*s;

	i = 0;
	m->started = 1;
	m->ants_str = string_join(m->ants_str, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((m->ants = ft_atoi(s)) <= 0)
		exit_function(m, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
			exit_function(m, 1);
	}
}
