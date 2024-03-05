/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:22:16 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/05 20:07:12 by cviegas          ###   ########.fr       */
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

size_t	find_x_exit(t_game g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g.map.block[i])
	{
		j = 0;
		while (g.map.block[i][j])
		{
			if (g.map.block[i][j] == 'E')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	find_y_exit(t_game g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g.map.block[i])
	{
		j = 0;
		while (g.map.block[i][j])
		{
			if (g.map.block[i][j] == 'E')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	collect(t_game *g)
{
	if (get_tile(g->draw.p_pos[0] + 0.5, g->draw.p_pos[1] + 0.5, *g) == 'C')
	{
		set_tile(g->draw.p_pos[0] + 0.5, g->draw.p_pos[1] + 0.5, '0', g);
		g->collected++;
	}
	(void)g;
	if (g->collected == g->goal && !g->collected_all)
	{
		g->collected_all = 1;
		set_tile(find_x_exit(*g), find_y_exit(*g), 'V', g);
	}
	if (g->collected_all)
	{
		if (get_tile(g->draw.p_pos[0] + 0.5, g->draw.p_pos[1] + 0.5, *g) == 'V')
			(ft_printf("%s%s%s%s%s\n", CLEAR, BOLD, P_GREEN,
					"Congratulations you Won!", RESET), clean_and_exit_game(g,
					0));
	}
}

void	collisions(t_game *g)
{
	g->draw.p_new_pos = faddmul(g->draw.p_pos, g->draw.p_vel, elapsed_time(g));
	// avoid_these_tiles('1', g);
	avoid_theses_tiles("1E", g);
	collect(g);
	g->draw.p_pos = g->draw.p_new_pos;
	if (!g->draw.p_vel[0] && !g->draw.p_vel[1])
		return ;
	g->tiles_traveled[0] += fabs(g->draw.p_vel[0]) * elapsed_time(g);
	g->tiles_traveled[1] += fabs(g->draw.p_vel[1]) * elapsed_time(g);
}
