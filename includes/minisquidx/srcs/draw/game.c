/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/27 11:25:34 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

void	draw_square(t_color color, int x, int y, t_game *g)
{
	t_v2i	i;

	i[0] = 0;
	while (i[0] < TILE_SIZE && x + i[0] < W_WIDTH)
	{
		i[1] = 0;
		while (i[1] < TILE_SIZE && y + i[1] < W_HEIGHT)
		{
			draw_color(color, (t_v2i){x + i[0], y + i[1]}, g);
			i[1]++;
		}
		i[0]++;
	}
}

bool	draw_tile(char c, size_t x, size_t y, t_game *g)
{
	if (c == '1' || c == 'P')
		draw_square(DARK_BROWN, x, y, g);
	else if (c == '0')
		draw_square(DARK_BLUE, x, y, g);
	else if (c == 'E')
		draw_square(GREEN, x, y, g);
	else if (c == 'C')
		draw_square(ORANGE, x, y, g);
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

void	draw_img(t_img *spr, t_v2i pos, t_game *g)
{
	t_v2i	i;

	i[1] = 0;
	while (i[1] < spr->size[1] && i[1] + pos[1] < W_HEIGHT)
	{
		i[0] = 0;
		while (i[0] < spr->size[0] && i[0] + pos[0] < W_WIDTH)
		{
			draw_color(get_color(*spr, i), i + pos, g);
			i[0]++;
		}
		i[1]++;
	}
}

void	draw_player(t_game *g)
{
	draw_img(g->draw.spr->player, (t_v2i){0, 0}, g);
}
