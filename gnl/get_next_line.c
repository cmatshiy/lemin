/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:18:02 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/27 10:43:21 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(const int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	char	*test;
	int		k;

	if ((k = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[k] = '\0';
		test = ft_strdup(*str);
		ft_strdel(&(*str));
		*str = ft_strjoin(test, buf);
		ft_strdel(&test);
	}
	return (k);
}

static void	finish(char **str, char *last)
{
	char	*next;

	next = ft_strdup(last + 1);
	ft_strdel(&(*str));
	*str = ft_strdup(next);
	ft_strdel(&next);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[5000];
	char		*last;
	int			k;

	if (fd < 0 || fd > INT_MAX - 1 || line == NULL)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while ((last = ft_strchr(str[fd], '\n')) == NULL)
	{
		if ((k = ft_read(fd, &str[fd])) < 0)
			return (-1);
		if (k == 0 && !last)
		{
			if (str[fd][0] == '\0')
				return (0);
			*line = ft_strdup(str[fd]);
			return (1);
		}
	}
	*line = ft_strsub(str[fd], 0, last - str[fd]);
	finish(&str[fd], last);
	return (1);
}
