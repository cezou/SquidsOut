/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/05 14:56:18 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

static bool	init_map_data(char **map, t_map_data *m, bool *valid)
{
	size_t	*player_pos;

	*valid = 1;
	m->char_map = map;
	m->map = turn_map_into_bool(map);
	if (!m->map)
		return (0);
	player_pos = player_starting_position(map);
	if (!player_pos)
		return (pa_free((void **)m->map), 0);
	m->x = player_pos[0];
	m->y = player_pos[1];
	p_free(player_pos);
	m->found_it = 0;
	return (1);
}

static void	search_for_something(t_map_data *m, int x, int y, char to_find)
{
	if (m->map[x][y])
		return ;
	m->map[x][y] = 1;
	if (m->char_map[x][y] == to_find)
		m->found_it = 1;
	search_for_something(m, x + 1, y, to_find);
	search_for_something(m, x - 1, y, to_find);
	search_for_something(m, x, y + 1, to_find);
	search_for_something(m, x, y - 1, to_find);
}

static void	search_for_every_squids(t_map_data *m)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (m->char_map[i])
	{
		j = 0;
		while (m->char_map[i][j])
		{
			if (m->char_map[i][j] == 'C')
			{
				m->found_it = 0;
				reset_bool_map(m->map, m->char_map);
				search_for_something(m, i, j, 'P');
				if (!m->found_it)
					return ;
			}
			j++;
		}
		i++;
	}
	m->found_it = 1;
}

bool	is_path_valid(char **map)
{
	t_map_data	map_data;
	bool		valid;

	if (!init_map_data(map, &map_data, &valid))
		return (0);
	search_for_something(&map_data, map_data.x, map_data.y, 'E');
	if (!map_data.found_it)
		(merr("Player can't find the exit"), valid = 0);
	search_for_every_squids(&map_data);
	if (!map_data.found_it)
		(merr("Player can't find at least one squid"), valid = 0);
	pa_free((void **)map_data.map);
	return (valid);
}
