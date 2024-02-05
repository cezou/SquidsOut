/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:21:19 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 11:05:57 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

static bool	is_rectangle(char **map)
{
	size_t	i;
	size_t	line_size;

	line_size = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (line_size != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static bool	is_surrounded_by_walls(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i] && map[i + 1])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

bool	is_valid_map(char **map)
{
	bool	valid;

	valid = 1;
	print_s(map);
	if (!is_rectangle(map))
		(merr("It isn't a rectangle"), valid = 0);
	if (is_there_unvalid_chars(map))
		(merr("There is at least one unvalid char:"),
			perr("     ● the only ones valid are '01CEP'"), valid = 0);
	if (!map[1] || !map[2] || !map[0][1] || !map[0][2])
		(merr("It is too small, it can't be surrounded by walls"),
			perr("     and contain '1 exit, at least 1 collectible,"),
			perr("     and 1 starting position' at the same time."), valid = 0);
	else
	{
		if (!is_surrounded_by_walls(map))
			(merr("It isn't surrounded by walls"), valid = 0);
		it_contains_everything(map, &valid);
	}
	// if (valid)
	// 	if (!is_valid_path(map))
	// 		(merr("The isn't a valid path for the player to finish the game."),
	// 			valid = 0);
	return (valid);
}
