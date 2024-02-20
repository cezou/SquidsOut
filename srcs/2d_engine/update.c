/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:49:00 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/20 11:16:09 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

void	update_game_data(t_game *g)
{
	update_camera(g);
}

void	draw_screen(t_game *g)
{
	draw_map(g);
}

int	update(t_game *g)
{
	update_game_data(g);
	draw_screen(g);
	put_color(WHITE, 0, 0, g);
	draw_player(g);
	return (0);
}
