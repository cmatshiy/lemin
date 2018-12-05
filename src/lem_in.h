/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:50:15 by cmatshiy          #+#    #+#             */
/*   Updated: 2018/09/24 13:19:44 by cmatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_m
{
	char	**rooms;
	char	*rooms_list;
	char	*ants_str;
	char	*links;
	int		qt_rooms;
	int		ants;
	int		started;
	int		curr_room;
	int		path_i;
	int		*path;
	int		**table;
	int		good[2];
	int		new_line;
	int		init_2;
}				t_m;

void	count_ants(t_m *m, char *line);
void	rooms(t_m *m, char *line);
void	links(t_m *m, char *line);

void	add_rooms(t_m *m);
void	create_table(t_m *m);
int		outcome(t_m *m, int i);

char	*string_join(char *s1, char *s2, int clean);
void	free_array(char **array, t_m *m, int error);
int		room_init(t_m *m, char *room_name, int start);

void	result(t_m *m);
void	print_grid_like(t_m *m);
void	exit_function(t_m *m, int error);

#endif
