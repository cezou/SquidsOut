/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:37:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/04 12:10:04 by cviegas          ###   ########.fr       */
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
				g->draw.p_pos[0] = j;
				g->draw.x_cam_pos = j;
				g->draw.p_pos[1] = i;
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
	g->draw.x_visible_tiles = W_WIDTH / TILE_SIZE;
	g->draw.y_visible_tiles = W_HEIGHT / TILE_SIZE;
	g->draw.x_offset = g->draw.x_cam_pos - (float)g->draw.x_visible_tiles / 2;
	g->draw.y_offset = g->draw.y_cam_pos - (float)g->draw.y_visible_tiles / 2;
	g->draw.p_vel[0] = 0;
	g->draw.p_vel[1] = 0;
	g->draw.p_new_pos[0] = 0;
	g->draw.p_new_pos[1] = 0;
	g->draw.p_pos[0] = 0;
	g->draw.p_pos[1] = 0;
	g->draw.map_offset[0] = 0;
	g->draw.map_offset[1] = 0;
	g->draw.offset[0] = 0;
	g->draw.offset[1] = 0;
	g->tiles_traveled = (t_v2f){0, 0};
	perr("Squidgame de merde");
}

void	init_game(t_game *g)
{
	start_stopwatch(&g->time);
	g->draw.spr = malloc(sizeof(t_sprites));
	if (!g->draw.spr)
		return (exit(FAIL));
	// g->draw.spr->p_idle = malloc(sizeof(t_animated_img));
	// if (!g->draw.spr->p_idle)
	// 	return (free(g->draw.spr), exit(FAIL));
	ft_bzero(g->draw.spr->p_idle.sprite, 8);
	g->screen = NU;
	g->draw.spr->squids = NU;
	g->draw.spr->player = NU;
	g->draw.spr->bg = NU;
	g->draw.spr->cage = NU;
	g->draw.spr->block = NU;
	g->map.block = NU;
	g->map.width = 0;
	g->mlx_win = NU;
	g->mlx = NU;
	ft_bzero(g->keys, MAX_KEYS + MAX_MOUSE);
}

void	init_player(t_game *g)
{
	int	i;

	g->draw.spr->player = init_xpm("squido2", g);
	i = -1;
	while (++i < 8)
	{
		g->draw.spr->p_idle.sprite[i] = init_animated_xpm("idle/", i, g);
		printf("sprite %d cree!\n", i);
	}
	g->draw.spr->p_idle.sprite[i] = NULL;
	g->draw.spr->p_idle.is_playing = 0;
	g->draw.spr->p_idle.frame = 0;
	g->draw.spr->p_idle.direction = 0;
}

void	init_sprites(t_game *g)
{
	g->screen = init_screen(g);
	init_player(g);
	g->draw.spr->block = init_xpm("block", g);
}

void	init_window(t_game *g)
{
	init_sprites(g);
	g->mlx_win = mlx_new_window(g->mlx, W_WIDTH, W_HEIGHT,
			"Squids Out (pre-alpha)");
	if (!g->mlx_win)
		clean_and_exit_game(g, FAIL);
}
