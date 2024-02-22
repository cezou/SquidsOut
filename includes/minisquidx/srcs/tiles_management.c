/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:17:13 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 09:48:56 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minisquidx.h"

char	get_tile(size_t x, size_t y, t_game g)
{
	if (!g.map.block[y][x] || x < 0 || x >= g.map.width || y < 0
		|| y >= g.map.height)
		return (merr("These tiles coordinates are out of boundaries"), 0);
	return (g.map.block[y][x]);
}

void	set_tile(size_t x, size_t y, char c, t_game *g)
{
	if (x >= 0 && x < g->map.width && y >= 0 && y < g->map.height)
		g->map.block[y][x] = c;
	else
		merr("These tiles coordinates are out of boundaries");
}
