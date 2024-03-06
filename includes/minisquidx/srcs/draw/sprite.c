/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:50:20 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 11:51:12 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

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
