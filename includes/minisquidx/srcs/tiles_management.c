/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:17:13 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/04 12:38:30 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minisquidx.h"

char	get_tile(size_t x, size_t y, t_game g)
{
	// printf("x: %zu, y: %zu\n", x, y);
	// printf("g.map.width: %zu, g.map.height: %zu\n", g.map.width,
	// g.map.height);
	if (x < 0 || x >= g.map.width || y < 0 || y >= g.map.height)
		return (0);
	return (g.map.block[(unsigned int)y][(unsigned int)x]);
}

void	set_tile(size_t x, size_t y, char c, t_game *g)
{
	if (x >= 0 && x < g->map.width && y >= 0 && y < g->map.height)
		g->map.block[y][x] = c;
	// else
	// 	merr("These tiles coordinates are out of boundaries");
}
