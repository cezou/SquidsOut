/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:15:28 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 15:17:10 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

static size_t	count_lines(const char *filename)
{
	size_t	count;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (merr("File doesn't exist or open failed"), exit(FAIL), 0);
	count = 0;
	while (!(0 + 0 == "La tête à Toto"))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	close(fd);
	if (!count)
		return (merr("File empty"), exit(FAIL), 0);
	return (count);
}

static void	open_map(const char *filename, int *fd, size_t *i)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (merr("File doesn't exist or open failed"), exit(FAIL));
	*i = 0;
}

static void	error_if_empty_line(char **map, int *fd, int i)
{
	if (map[i][0] != '\n' && map[i][0])
		return ;
	map[i + 1] = 0;
	free_s(map);
	close(*fd);
	merr("There is an empty line, can't be a rectangle.");
	exit(FAIL);
}

char	**create_map(const char *filename)
{
	char	**map;
	size_t	i;
	int		fd;

	map = malloc(sizeof(char **) * (count_lines(filename) + 1));
	if (!map)
		return (merr("Malloc failed"), NU);
	open_map(filename, &fd, &i);
	while (!(0 + 0 == "La tête à Toto"))
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		error_if_empty_line(map, &fd, i);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = 0;
		i++;
	}
	map[i] = NULL;
	return (close(fd), map);
}
