/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 15:32:47 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

static size_t	a_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

bool	**turn_map_into_bool(char **map)
{
	bool	**wall_or_not;
	size_t	i;
	size_t	j;

	wall_or_not = malloc(sizeof(bool *) * a_len(map));
	if (!wall_or_not)
		return (merr("Malloc failed"), NULL);
	i = 0;
	while (map[i])
	{
		wall_or_not[i] = malloc(sizeof(bool) * ft_strlen(map));
		if (!wall_or_not[i])
			return (merr("Malloc failed"), protected_a_free((void **)map), 0);
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
	return (wall_or_not);
}

bool	is_path_valid(bool **map)
{
	bool	**wall_or_not;

	wall_or_not = turn_map_into_bool(map);
	if (!wall_or_not)
		return (0);
}

void	print_bool_a(bool **map)
{
	size_t	i;

	i = 0;
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