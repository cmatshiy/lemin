/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:49:44 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/24 17:25:22 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_array(char **array, t_m *m, int error)
{
	int	i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	if (error)
		exit_function(m, 1);
	array = NULL;
}
