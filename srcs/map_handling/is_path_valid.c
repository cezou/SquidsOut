/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 18:46:10 by cviegas          ###   ########.fr       */
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

bool	search_for_exit(bool **map, char **char_map, size_t x, size_t y)
{
	if (char_map[x][y] == 'E')
		return (1);
	if (map[x][y])
		return (0);
	map[x][y] = 1;
	if (!map[x + 1][y] && char_map[x + 1][y])
	{
		ft_printf(" |\n");
		ft_printf(" v\n");
		search_for_exit(map, char_map, x + 1, y);
	}
	if (!map[x - 1][y] && (x - 1 > 0))
	{
		ft_printf(" A\n");
		ft_printf(" |\n");
		search_for_exit(map, char_map, x - 1, y);
	}
	if (!map[x][y + 1] && char_map[x][y + 1])
	{
		ft_printf(" -->\n");
		search_for_exit(map, char_map, x, y + 1);
	}
	if (!map[x][y - 1] && (y - 1 > 0))
	{
		ft_printf(" <--\n");
		search_for_exit(map, char_map, x, y - 1);
	}
	return (0);
}

bool	is_path_valid(char **map)
{
	bool	**wall_or_not;
	bool	valid_path;
	size_t	*player_pos;

	wall_or_not = turn_map_into_bool(map);
	if (!wall_or_not)
		return (0);
	player_pos = player_starting_position(map);
	if (!player_pos)
		return (protected_a_free((void **)wall_or_not), 0);
	valid_path = 0;
	search_for_exit(wall_or_not, map, player_pos[0], player_pos[1]);
	print_bool_a(wall_or_not, map);
	ft_printf("\n");
	print_s(map);
	protected_a_free((void **)wall_or_not);
	protected_free(player_pos);
	return (valid_path);
}

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