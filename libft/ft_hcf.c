/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hcf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:25:21 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 13:25:27 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_hcf(unsigned int a, unsigned int b)
{
	unsigned int hcf;
	unsigned int temp;

	hcf = 1;
	temp = 1;
	while (temp <= a && temp <= b)
	{
		if (a % temp == 0 && b % temp == 0)
			hcf = temp;
		temp++;
	}
	return (hcf);
}
