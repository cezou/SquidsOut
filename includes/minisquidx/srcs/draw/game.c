/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/05 19:14:18 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

t_v2i	fadd(t_v2f a, t_v2f b)
{
	return ((t_v2i){a[0] + b[0], a[1] + b[1]});
}

t_v2i	fsub(t_v2f a, t_v2f b)
{
	return ((t_v2i){(a[0] - b[0]) * TILE_SIZE, (a[1] - b[1]) * TILE_SIZE});
}

t_v2i	i_add_s(t_v2i a, t_v2i b, size_t s)
{
	return ((t_v2i){(a[0] + b[0]) * s - s, (a[1] + b[1]) * s - s});
}

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
		draw_square(DARK_BLUE, x, y, g);
	else if (c == 'E')
		draw_square(BLUE, x, y, g);
	else if (c == 'V')
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
			tile = get_tile(x + g->draw.x_offset, y + g->draw.y_offset, *g);
			if (!tile)
				break ;
			if (!draw_tile(tile, (x)*TILE_SIZE - g->draw.map_offset[0],
					(y)*TILE_SIZE - g->draw.map_offset[1], g))
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

void	draw_scaled_img(t_img *spr, t_v2i pos, size_t scale, t_game *g)
{
	t_v2i	i;
	t_v2i	s;

	i[1] = 0;
	while (i[1] < spr->size[1] && i[1] + pos[1] < W_HEIGHT)
	{
		i[0] = 0;
		while (i[0] < spr->size[0] && i[0] + pos[0] < W_WIDTH)
		{
			s[1] = 0;
			while (s[1] < scale)
			{
				s[0] = 0;
				while (s[0] < scale)
				{
					draw_color(get_color(*spr, i), s + pos + i * (t_v2i){scale,
						scale}, g);
					s[0]++;
				}
				s[1]++;
			}
			i[0]++;
		}
		i[1]++;
	}
}

void	idle_animation_play(t_game *g, t_sprites *s)
{
	if (s->p_idle.is_playing)
	{
		update_stopwatch(&s->p_idle.time);
		if (!s->p_idle.direction && (get_time(s->p_idle.time) > (s->p_idle.frame
					+ 1) * 120))
			s->p_idle.frame++;
		if (s->p_idle.direction && (get_time(s->p_idle.time) > (8
					- s->p_idle.frame + 1) * 120))
			s->p_idle.frame--;
		if (s->p_idle.frame == 8)
		{
			s->p_idle.direction = 1;
			start_stopwatch(&s->p_idle.time);
			s->p_idle.frame--;
		}
		if (s->p_idle.frame == -1)
		{
			s->p_idle.direction = 0;
			s->p_idle.frame++;
			start_stopwatch(&s->p_idle.time);
		}
		s->player->pixels = s->p_idle.sprite[s->p_idle.frame]->pixels;
	}
}

void	idle_animation(t_game *g, t_sprites *s)
{
	if (s->p_idle.is_playing && (g->draw.p_vel[0] != 0
			|| g->draw.p_vel[1] != 0))
	{
		s->p_idle.is_playing = 0;
		s->p_idle.frame = 0;
		s->p_idle.direction = 0;
	}
	if ((g->draw.p_vel[0] == 0 || g->draw.p_vel[1] == 0)
		&& !s->p_idle.is_playing)
		(start_stopwatch(&s->p_idle.time), g->draw.spr->p_idle.is_playing = 1);
	idle_animation_play(g, s);
}

void	draw_player(t_game *g)
{
	idle_animation(g, g->draw.spr);
	draw_scaled_img(g->draw.spr->player, fsub(g->draw.p_pos,
			(t_v2f){g->draw.x_offset, g->draw.y_offset}), 3, g);
}

void	draw_infos(t_game *g)
{
	char	*x;
	char	*y;
	char	*xplusy;

	mlx_string_put(g->mlx, g->mlx_win, 48, 48, 0xFFFFFF, "Traveled");
	xplusy = ft_itoa((int)(g->tiles_traveled[0] + g->tiles_traveled[1]));
	if (!xplusy)
		(perr("Itoa's Malloc Failed"), clean_and_exit_game(g, 1));
	x = ft_itoa((int)g->tiles_traveled[0]);
	if (!x)
		(perr("Itoa's Malloc Failed"), free(xplusy), clean_and_exit_game(g, 1));
	y = ft_itoa((int)g->tiles_traveled[1]);
	if (!y)
		(perr("Itoa's Malloc Failed"), free(xplusy), free(x),
			clean_and_exit_game(g, 1));
	// string put le nombre xplusy a cote de Traveled ≈
	mlx_string_put(g->mlx, g->mlx_win, 100, 48, 0xFFFFFF, xplusy);
	mlx_string_put(g->mlx, g->mlx_win, 48, 64, 0xFFFFFF, "X:");
	mlx_string_put(g->mlx, g->mlx_win, 64, 64, 0xFFFFFF, x);
	mlx_string_put(g->mlx, g->mlx_win, 48, 80, 0xFFFFFF, "Y:");
	mlx_string_put(g->mlx, g->mlx_win, 64, 80, 0xFFFFFF, y);
	free(xplusy);
	free(x);
	free(y);
}
