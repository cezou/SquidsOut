/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 17:13:55 by cviegas          ###   ########.fr       */
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
	return (wall_or_not);
}

void	print_bool_a(bool **map, char **chars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (chars[i])
	{
		j = 0;
		while (chars[i][j])
		{
			ft_printf("%d", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

bool	is_path_valid(char **map)
{
	bool	**wall_or_not;

	wall_or_not = turn_map_into_bool(map);
	if (!wall_or_not)
		return (0);
	print_bool_a(wall_or_not, map);
	return (1);
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