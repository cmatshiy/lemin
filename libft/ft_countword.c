/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:24:47 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 13:24:58 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(const char *str, int c)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c)
				i++;
			num++;
		}
		i++;
	}
	return (num);
}
