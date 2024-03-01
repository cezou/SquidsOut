/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:22:16 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/01 20:19:27 by cviegas          ###   ########.fr       */
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
			|| get_tile(g->draw.p_new_pos[0] + 0.9, g->draw.p_pos[1], *g) == c)
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

void	avoid_this_block(char c, t_game *g)
{
	avoid_this_block_left_right(g, c);
	avoid_this_block_up_down(g, c);
}

void	collisions(t_game *g)
{
	g->draw.p_new_pos = faddmul(g->draw.p_pos, g->draw.p_vel, elapsed_time(g));
	avoid_this_block('1', g);
	g->draw.p_pos = g->draw.p_new_pos;
}
