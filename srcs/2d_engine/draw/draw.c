/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/16 20:14:06 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/squids_out.h"

bool	draw_tile(char c, size_t x, size_t y, t_game *g)
{
	if (c == '1')
		put_color(BLACK, x, y, g);
	else if (c == '0')
		put_color(DARK_BLUE, x, y, g);
	else if (c == 'E')
		put_color(GREEN, x, y, g);
	else if (c == 'P')
		put_color(WHITE, x, y, g);
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

	y = 0;
	while (y < g->draw.y_visible_tiles)
	{
		x = 0;
		while (x < g->draw.x_visible_tiles)
		{
			tile = get_tile(x, y, *g);
			if (!tile)
				break ;
			if (!draw_tile(tile, x, y, g))
				perr("Sprite or Color not found for this char.");
			x++;
		}
		y++;
	}
}
