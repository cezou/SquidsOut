/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 20:41:57 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

bool	**turn_map_into_bool(char **map)
{
	bool	**wall_or_not;
	size_t	i;
	size_t	j;

	wall_or_not = malloc(sizeof(bool *) * (a_len(map) + 1));
	if (!wall_or_not)
		return (merr("Malloc failed"), NULL);
	i = 0;
	while (map[i])
	{
		wall_or_not[i] = malloc(sizeof(bool) * ft_strlen(map[i]));
		if (!wall_or_not[i])
			return (merr("Malloc failed"), protected_a_free((void **)map), NU);
		j = 0;
		while (map[i][j])
		{
			wall_or_not[i][j] = 0;
			if (map[i][j] == '1')
				wall_or_not[i][j] = 1;
			j++;
		}
		i++;
	}
	wall_or_not[i] = NULL;
	return (wall_or_not);
}
size_t	*player_starting_position(char **map)
{
	size_t	i;
	size_t	j;
	size_t	*player_coords;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player_coords = malloc(sizeof(size_t) * 2);
				if (!player_coords)
					return (merr("Malloc failed"), NULL);
				player_coords[0] = i;
				player_coords[1] = j;
				return (player_coords);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	search_for_something(t_map_data *m, int x, int y, char to_find)
{
	if (m->char_map[x][y] == to_find || m->found_it)
	{
		m->map[x][y] = 1;
		m->found_it = 1;
		return ;
	}
	if (m->map[x][y])
		return ;
	m->map[x][y] = 1;
	if (!m->map[x + 1][y] && m->char_map[x + 1][y])
		search_for_something(m, ++x, y, to_find);
	if (!m->map[x - 1][y] && (x - 1 > 0))
		search_for_something(m, --x, y, to_find);
	if (!m->map[x][y + 1] && m->char_map[x][y + 1])
		search_for_something(m, x, ++y, to_find);
	if (!m->map[x][y - 1] && (y - 1 > 0))
		search_for_something(m, x, --y, to_find);
}

bool	init_map_data(char **map, t_map_data *m)
{
	size_t	*player_pos;

	m->char_map = map;
	m->map = turn_map_into_bool(map);
	if (!m->map)
		return (0);
	player_pos = player_starting_position(map);
	if (!player_pos)
		return (protected_a_free((void **)m->map), 0);
	m->x = player_pos[0];
	m->y = player_pos[1];
	protected_free(player_pos);
	m->found_it = 0;
	return (1);
}

bool	is_path_valid(char **map)
{
	t_map_data	map_data;

	if (!init_map_data(map, &map_data))
		return (0);
	search_for_something(&map_data, map_data.x, map_data.y, 'E');
	if (!map_data.found_it)
		merr("Player can't find the exit");
	print_bool_a(map_data.map, map);
	ft_printf("\n");
	print_s(map);
	protected_a_free((void **)map_data.map);
	return (map_data.found_it);
}

// void	search_for_exit(t_map_data *m, int x, int y)
// {
// 	if (m->char_map[x][y] == 'E' || m->found_it)
// 	{
// 		m->map[x][y] = 1;
// 		m->found_it = 1;
// 		return ;
// 	}
// 	if (m->map[x][y])
// 		return ;
// 	m->map[x][y] = 1;
// 	ft_printf("Player pos: x: %d, y: %d\n", x, y);
// 	if (!m->map[x + 1][y] && m->char_map[x + 1][y])
// 	{
// 		ft_printf(" |\n");
// 		ft_printf(" v\n");
// 		x++;
// 		search_for_exit(m, x, y);
// 	}
// 	if (!m->map[x - 1][y] && (x - 1 > 0))
// 	{
// 		ft_printf(" A\n");
// 		ft_printf(" |\n");
// 		x--;
// 		search_for_exit(m, x, y);
// 	}
// 	if (!m->map[x][y + 1] && m->char_map[x][y + 1])
// 	{
// 		ft_printf(" -->\n");
// 		y++;
// 		search_for_exit(m, x, y);
// 	}
// 	if (!m->map[x][y - 1] && (y - 1 > 0))
// 	{
// 		ft_printf(" <--\n");
// 		y--;
// 		search_for_exit(m, x, y--);
// 	}
// }

// fun **map *valid, int *tab Coord
// if (coord == sortie || coord out)
// 	valid = 1
// 	return ;
// else
// 	if (coord +x != wall)
// 	fun (map valid coord +x)
// 	if coord -x != wall
// 	fun (map valid coord -x)

// OLD
//
// void	search_for_exit(bool **map, char **char_map, size_t *p_pos, bool *valid)
// {
// 	size_t	*next_pos;

// 	next_pos = NULL;
// 	if (char_map[p_pos[0]][p_pos[1]] == 'E' || *valid)
// 	{
// 		protected_free(next_pos);
// 		*valid = 1;
// 		return ;
// 	}
// 	if (map[p_pos[0]][p_pos[1]])
// 	{
// 		protected_free(next_pos);
// 		return ;
// 	}
// 	map[p_pos[0]][p_pos[1]] = 1;
// 	next_pos = pos_dup(p_pos);
// 	if (!map[p_pos[0] + 1][p_pos[1]] && char_map[p_pos[0] + 1][p_pos[1]])
// 	{
// 		ft_printf(" |\n");
// 		ft_printf(" v\n");
// 		next_pos[0]++;
// 		search_for_exit(map, char_map, next_pos, valid);
// 	}
// 	if (!map[p_pos[0] - 1][p_pos[1]] && (p_pos[0] - 1 > 0))
// 	{
// 		ft_printf(" A\n");
// 		ft_printf(" |\n");
// 		next_pos[0]--;
// 		search_for_exit(map, char_map, next_pos, valid);
// 	}
// 	if (!map[p_pos[0]][p_pos[1] + 1] && char_map[p_pos[0]][p_pos[1] + 1])
// 	{
// 		ft_printf(" -->\n");
// 		next_pos[1]++;
// 		search_for_exit(map, char_map, next_pos, valid);
// 	}
// 	if (!map[p_pos[0]][p_pos[1] - 1] && (p_pos[1] - 1 > 0))
// 	{
// 		ft_printf(" <--\n");
// 		next_pos[1]--;
// 		search_for_exit(map, char_map, next_pos, valid);
// 	}
// 	protected_free(next_pos);
// }