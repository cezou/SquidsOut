/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:49:00 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/27 10:21:12 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	update_game_data(t_game *g)
{
	update_camera(g);
}
void	update_screen(t_game *g)
{
	update_game_data(g);
	draw_map(g);
	draw_player(g);
	draw_square(PINK, 15, 15, g);
}

int	update(t_game *g)
{
	update_screen(g);
	print_screen(g);
	return (0);
}
