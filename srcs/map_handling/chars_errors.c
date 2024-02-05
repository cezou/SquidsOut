/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:31:29 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 10:51:19 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

static bool	is_valid_char(const char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (0);
	return (1);
}

bool	is_there_unvalid_chars(char **map)
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

static bool	is_there_this_char(char **map, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static bool	is_there_one_and_only_one(char **map, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			if (count > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	it_contains_everything(char **map, bool *valid)
{
	if (!is_there_this_char(map, 'E'))
		(merr("It must contain 1 exit ('E')"), *valid = 0);
	if (!is_there_one_and_only_one(map, 'E'))
		(merr("It must contain 1 and only 1 exit ('E')"), *valid = 0);
	if (!is_there_this_char(map, 'P'))
		(merr("It must contain 1 starting position ('P')"), *valid = 0);
	if (!is_there_one_and_only_one(map, 'P'))
		(merr("It must contain 1 and only 1 starting position ('P')"),
			*valid = 0);
	if (!is_there_this_char(map, 'C'))
		(merr("It must contain at least 1 collectible ('C')"), *valid = 0);
}
