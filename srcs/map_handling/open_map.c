/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:38:25 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/02 19:24:05 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

size_t	count_lines(const int fd)
{
	size_t	count;
	char	*line;

	count = 0;
	while (!(0 + 0 == "la tete a toto"))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	return (count);
}

char	**create_map(const int filename)
{
	char	**map;
	size_t	nb_lines;
	size_t	i;

	nb_lines = count_lines(filename);
	if (!nb_lines)
		return (perr("File empty"), NULL);
	map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		return (perr("Malloc failed"), NULL);
	i = 0;
	while (i < nb_lines)
	{
		map[i] = get_next_line(filename);
		if (!map[i])
			return (perr("Malloc failed"), free_s(map), NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

bool	not_ber_ended(const char *s)
{
	int	i;

	if (ft_strlen(s) < 5)
		return (1);
	i = ft_strlen(s) - 1;
	if (s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.')
		return (0);
	return (1);
}

void	handle_map(const char *file)
{
	if (not_ber_ended(file))
		return (perr("File is not a .ber"));
}
