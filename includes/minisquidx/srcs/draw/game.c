/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 12:07:05 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

void	draw_player(t_game *g)
{
	draw_scaled_img(g->draw.spr->player, fsub(g->draw.p_pos,
			(t_v2f){g->draw.x_offset, g->draw.y_offset}), 3, g);
}

void	draw_map(t_game *g)
{
	char	tile;
	size_t	x;
	size_t	y;

	tile = 0;
	y = 0;
	while (g->map.block[y])
	{
		x = 0;
		while (g->map.block[y][x])
		{
			tile = get_tile(x + g->draw.x_offset, y + g->draw.y_offset, *g);
			if (!tile)
				break ;
			if (!draw_tile(tile, x * TILE_SIZE - g->draw.map_offset[0], y
					* TILE_SIZE - g->draw.map_offset[1], g))
				perr("Sprite or Color not found for this char.");
			x++;
		}
		y++;
	}
}
