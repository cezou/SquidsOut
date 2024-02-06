/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:38:25 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/06 12:07:47 by cviegas          ###   ########.fr       */
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

void	reset_bool_map(bool **bool_map, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			bool_map[i][j] = 0;
			if (map[i][j] == '1')
				bool_map[i][j] = 1;
			j++;
		}
		i++;
	}
	bool_map[i] = NULL;
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

void	print_bool_a(bool **map, char **chars)
{
	size_t	i;
	size_t	j;
	char	c;

	c = 'a';
	i = 0;
	ft_printf("\n");
	while (chars[i])
	{
		j = 0;
		ft_printf("%c: ", c++);
		while (chars[i][j])
		{
			ft_printf("%d", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

size_t	a_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
