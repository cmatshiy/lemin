/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:49:02 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 13:49:06 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[k] != '\0')
	{
		s1[i + k] = s2[k];
		k++;
	}
	s1[i + k] = '\0';
	return (s1);
}
