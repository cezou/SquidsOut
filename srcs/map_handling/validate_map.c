/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:21:19 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/04 21:29:52 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

static bool	is_valid_char(const char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (0);
	return (1);
}

static bool	there_is_unvalid_chars(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	// Intermediaire et last;
	return (1);
}

bool	is_valid_map(char **map)
{
	print_s(map);
	if (there_is_unvalid_chars(map))
		return (merr("There is at least one unvalid char"), 0);
	if (!is_rectangle(map))
		return (merr("The map isn't a rectangle."), 0);
	if (!is_surrounded_by_walls(map))
		return (merr("The map isn't surrounded by walls."), 0);
	return (1);
}
