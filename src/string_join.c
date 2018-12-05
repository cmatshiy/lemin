/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:55:26 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/23 14:02:05 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*string_join(char *s1, char *s2, int clean)
{
	char *new_str;

	new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0] == 0)
		return (s2);
	ft_strcat(new_str, s1);
	ft_strcat(new_str, "\n");
	ft_strcat(new_str, s2);
	ft_strdel(&s1);
	(clean) ? ft_strdel(&s2) : 0;
	return (new_str);
}
