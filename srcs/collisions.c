/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:22:16 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/04 11:57:30 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

t_v2f	faddmul(t_v2f a, t_v2f b, float s)
{
	return ((t_v2f){a[0] + b[0] * s, a[1] + b[1] * s});
}

void	avoid_this_block_left_right(t_game *g, char c)
{
	if (g->draw.p_vel[0] <= 0)
	{
		if (get_tile(g->draw.p_new_pos[0], g->draw.p_pos[1], *g) == c
			|| get_tile(g->draw.p_new_pos[0], g->draw.p_pos[1] + 0.9, *g) == c)
		{
			g->draw.p_new_pos[0] = (int)g->draw.p_new_pos[0] + 1;
			g->draw.p_vel[0] = 0;
		}
	}
	else
	{
		if (get_tile(g->draw.p_new_pos[0] + 1, g->draw.p_pos[1], *g) == c
			|| get_tile(g->draw.p_new_pos[0] + 1, g->draw.p_pos[1] + 0.9,
				*g) == c)
		{
			g->draw.p_new_pos[0] = (int)g->draw.p_new_pos[0];
			g->draw.p_vel[0] = 0;
		}
	}
}

void	avoid_this_block_up_down(t_game *g, char c)
{
	if (g->draw.p_vel[1] <= 0)
	{
		if (get_tile(g->draw.p_new_pos[0], g->draw.p_new_pos[1], *g) == c
			|| get_tile(g->draw.p_new_pos[0] + 0.9, g->draw.p_new_pos[1],
				*g) == c)
		{
			g->draw.p_new_pos[1] = (int)g->draw.p_new_pos[1] + 1;
			g->draw.p_vel[1] = 0;
		}
	}
	else
	{
		if (get_tile(g->draw.p_new_pos[0], g->draw.p_new_pos[1] + 1, *g) == c
			|| get_tile(g->draw.p_new_pos[0] + 0.9, g->draw.p_pos[1] + 1,
				*g) == c)
		{
			g->draw.p_new_pos[1] = (int)g->draw.p_new_pos[1];
			g->draw.p_vel[1] = 0;
		}
	}
}

void	avoid_this_tile(char c, t_game *g)
{
	avoid_this_block_left_right(g, c);
	avoid_this_block_up_down(g, c);
}

void	avoid_theses_tiles(char *tiles_to_avoid, t_game *g)
{
	size_t	i;

	i = 0;
	if (!tiles_to_avoid || !tiles_to_avoid[0])
		return ;
	while (tiles_to_avoid[i])
		avoid_this_tile(tiles_to_avoid[i++], g);
}

void	collisions(t_game *g)
{
	g->draw.p_new_pos = faddmul(g->draw.p_pos, g->draw.p_vel, elapsed_time(g));
	avoid_this_tile('1', g);
	// avoid_theses_tiles("1C", g);
	g->draw.p_pos = g->draw.p_new_pos;
	if (!g->draw.p_vel[0] && !g->draw.p_vel[1])
		return ;
	// g->tiles_traveled[0] += g->draw.p_vel[0] * elapsed_time(g);
	// g->tiles_traveled[1] += g->draw.p_vel[1] * elapsed_time(g);
	// ft_printf("Tiles traveled: X = %f, Y = %f\n", g->tiles_traveled[0],
	// 	g->tiles_traveled[1]);
}
