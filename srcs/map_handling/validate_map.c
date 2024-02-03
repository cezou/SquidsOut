/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:21:19 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/03 17:26:57 by cviegas          ###   ########.fr       */
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
	j = 0;
	while (map[i])
	{
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

bool	is_valid_map(char **map)
{
	if (there_is_unvalid_chars(map))
		return (merr("There is unvalid char(s)"), 0);
	return (1);
}
