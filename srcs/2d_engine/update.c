/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:49:00 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/16 20:09:38 by cviegas          ###   ########.fr       */
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
	return (0);
}
