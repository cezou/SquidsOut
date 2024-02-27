/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:49:00 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/27 17:13:32 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	events(t_game *g)
{
	p_movements(g);
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
	// printf("p_pos : X= %f\n        Y= %f\n", g->draw.p_pos[0],
	// 	g->draw.p_pos[1]);
	return (0);
}
