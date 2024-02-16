/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/16 17:55:17 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

void	draw_map(t_game g)
{
	char	tile;
	size_t	x;
	size_t	y;

	x = 0;
	while (g.map.block[x])
	{
		y = 0;
		while (g.map.block[x][y])
		{
			tile = get_tile(x, y, g);
			// draw_tile(char c, size_t x, size_t y)
			y++;
		}
		x++;
	}
}
