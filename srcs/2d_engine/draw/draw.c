/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/20 10:56:11 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/squids_out.h"

bool	draw_tile(char c, size_t x, size_t y, t_game *g)
{
	if (c == '1' || c == 'P')
		put_color(DARK_BROWN, x, y, g);
	else if (c == '0')
		put_color(DARK_BLUE, x, y, g);
	else if (c == 'E')
		put_color(GREEN, x, y, g);
	else if (c == 'C')
		put_color(ORANGE, x, y, g);
	else
		return (0);
	return (1);
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
			tile = get_tile(x, y, *g);
			if (!tile)
				break ;
			if (!draw_tile(tile, (float)(x)*TILE_SIZE, (float)(y)*TILE_SIZE, g))
				perr("Sprite or Color not found for this char.");
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *g)
{
	put_color(WHITE, g->map.x_p_pos - g->draw.x_offset, g->map.y_p_pos
		- g->draw.y_offset, g);
}
