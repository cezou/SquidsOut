/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:37:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/20 10:46:12 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

static void	get_p_pos(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g->map.block[i])
	{
		j = 0;
		while (g->map.block[i][j])
		{
			if (g->map.block[i][j] == 'P')
			{
				g->map.x_p_pos = j;
				g->draw.x_cam_pos = j;
				g->map.y_p_pos = i;
				g->draw.y_cam_pos = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_data(t_game *g)
{
	get_p_pos(g);
	g->draw.x_visible_tiles = W_WIDTH / g->map.width + 1;
	g->draw.y_visible_tiles = W_HEIGHT / g->map.height + 1;
	g->draw.x_offset = g->draw.x_cam_pos - (float)g->draw.x_visible_tiles / 2;
	g->draw.y_offset = g->draw.y_cam_pos - (float)g->draw.y_visible_tiles / 2;
}

void	init_game(t_game *g)
{
	g->spr = malloc(sizeof(t_sprites));
	if (!g->spr)
		return (exit(FAIL));
	g->spr->bg.img = NULL;
	g->map.block = NU;
	g->map.width = 0;
	g->mlx_win = NU;
	g->mlx = NU;
}

void	init_window(t_game *g)
{
	g->spr->bg = init_xpm("bg", g);
	g->mlx_win = mlx_new_window(g->mlx, W_WIDTH, W_HEIGHT,
			"Squids Out (pre-alpha)");
	if (!g->mlx_win)
		clean_and_exit_game(g, FAIL);
}
