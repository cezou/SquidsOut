/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 09:48:48 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minisquidx.h"

static void	clamp_cam_topleft(float *offset)
{
	if (*offset > 0)
		*offset = 0;
}

// So the camera can't get out of the map boundaries
static void	clamp_cam(t_game *g)
{
	clamp_cam_topleft(&g->draw.x_offset);
	clamp_cam_topleft(&g->draw.y_offset);
	if (g->draw.x_offset > g->map.width - g->draw.x_visible_tiles)
		g->draw.x_offset = g->map.width - g->draw.x_visible_tiles;
	if (g->draw.y_offset > g->map.width - g->draw.y_visible_tiles)
		g->draw.y_offset = g->map.width - g->draw.y_visible_tiles;
}

// Stick the camera to the player and offset if on boundaries.
static void	update_cam_data(t_game *g)
{
	g->draw.x_cam_pos = g->map.x_p_pos;
	g->draw.y_cam_pos = g->map.y_p_pos;
	g->draw.x_offset = g->draw.x_cam_pos - (float)g->draw.x_visible_tiles / 2;
	g->draw.y_offset = g->draw.y_cam_pos - (float)g->draw.y_visible_tiles / 2;
}

// Stick the camera to the player and offset if the player is over
// the boundaries of the map.
void	update_camera(t_game *g)
{
	update_cam_data(g);
	clamp_cam(g);
}
