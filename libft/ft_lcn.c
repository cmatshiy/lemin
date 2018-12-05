/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:31:42 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/25 13:31:47 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;

	lcm = (a * b) / ft_hcf(a, b);
	return (lcm);
}
