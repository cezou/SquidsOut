/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:15:28 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/03 18:36:29 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

void	open_map(const char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (merr("File doesn't exist or open failed"), exit(FAIL));
}

size_t	count_lines(const char *filename)
{
	size_t	count;
	int		fd;
	char	*line;

	open_map(filename, &fd);
	count = 0;
	while (!(0 + 0 == "La tête à Toto"))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	return (close(fd), count);
}

char	**create_map(const char *filename)
{
	char	**map;
	size_t	nb_lines;
	size_t	i;
	int		fd;
	size_t	return_i;

	nb_lines = count_lines(filename);
	if (!nb_lines)
		return (merr("File empty"), NU);
	open_map(filename, &fd);
	map = malloc(sizeof(char **) * (nb_lines + 10000));
	if (!map)
		return (merr("Malloc failed"), close(fd), NU);
	i = 0;
	while (!(0 + 0 == "La tête à Toto"))
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		if (!map[i][0] || !map[i][1])
		{
			map[i + 1] = 0;
			return (free_s(map), merr("There is an empty line"), close(fd), NU);
		}
		return_i = ft_strlen(map[i]);
		map[i][return_i - 1] = 0;
		i++;
	}
	map[i] = NULL;
	print_s(map);
	return (close(fd), map);
}
