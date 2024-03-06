/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:27:54 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 11:51:34 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

void	draw_square(t_color color, int x, int y, t_game *g)
{
	t_v2i	i;

	i[0] = 0;
	while (i[0] < TILE_SIZE)
	{
		i[1] = 0;
		while (i[1] < TILE_SIZE)
		{
			if (x + i[0] < W_WIDTH && y + i[1] < W_HEIGHT)
				draw_color(color, (t_v2i){x + i[0], y + i[1]}, g);
			i[1]++;
		}
		i[0]++;
	}
}

bool	draw_tile(char c, size_t x, size_t y, t_game *g)
{
	if (c == '1')
		draw_scaled_img(g->draw.spr->block, (t_v2i){x, y}, 3, g);
	else if (c == '0' || c == 'P')
		draw_square((t_color)DARK_BLUE, x, y, g);
	else if (c == 'E')
		draw_square((t_color)BLUE, x, y, g);
	else if (c == 'V')
		draw_square((t_color)GREEN, x, y, g);
	else if (c == 'C')
		draw_square((t_color)ORANGE, x, y, g);
	else
		return (0);
	return (1);
}
