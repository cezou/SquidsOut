/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:28:32 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 13:51:54 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

// Encode RGB values into an integer
int	rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

void	put_pixel(int color, int x, int y, t_game *g)
{
	mlx_pixel_put(g->mlx, g->mlx_win, x, y, color);
}

// Draw a TILE_SIZE colored square
void	put_square(int color, int x, int y, t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			put_pixel(color, x + i, y + j, g);
			j++;
		}
		i++;
	}
}
