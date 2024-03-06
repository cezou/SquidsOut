/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:49:00 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 16:31:28 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	events(t_game *g)
{
	p_movements(g);
	collisions(g);
	escape(g);
}

void	update_game_data(t_game *g)
{
	events(g);
	update_camera(g);
}

void	update_screen(t_game *g)
{
	update_game_data(g);
	draw_map(g);
	draw_player(g);
}

int	update(t_game *g)
{
	update_screen(g);
	print_screen(g);
	if (g->draw.p_vel[0] != 0 || g->draw.p_vel[1] != 0)
		ft_printf("%sTiles traveled ≈ %d\nX: %d\nY: %d\n", CLEAR,
			(int)(g->tiles_traveled[0] + g->tiles_traveled[1]),
			(int)g->tiles_traveled[0], (int)g->tiles_traveled[1]);
	return (0);
}
