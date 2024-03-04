/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:03 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/04 11:57:30 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minisquidx.h"

static void	clamp_cam_topleft(float *offset)
{
	if (*offset < 0)
		*offset = 0;
}

// So the camera can't get out of the map boundaries
static void	clamp_cam(t_game *g)
{
	clamp_cam_topleft(&g->draw.x_offset);
	clamp_cam_topleft(&g->draw.y_offset);
	if (g->draw.x_offset > g->map.width - g->draw.x_visible_tiles - 1)
		g->draw.x_offset = g->map.width - g->draw.x_visible_tiles - 1;
	if (g->draw.y_offset > g->map.height - g->draw.y_visible_tiles - 0.25)
		g->draw.y_offset = g->map.height - g->draw.y_visible_tiles - 0.25;
}

// Stick the camera to the player and offset if on boundaries.
static void	update_cam_data(t_game *g)
{
	g->draw.x_cam_pos = g->draw.p_pos[0];
	g->draw.y_cam_pos = g->draw.p_pos[1];
	g->draw.x_offset = g->draw.x_cam_pos - (float)g->draw.x_visible_tiles / 2;
	g->draw.y_offset = g->draw.y_cam_pos - (float)g->draw.y_visible_tiles / 2;
}

static void	map_offset(t_game *g)
{
	g->draw.map_offset[0] = (g->draw.x_offset - (int)g->draw.x_offset)
		* TILE_SIZE;
	g->draw.map_offset[1] = (g->draw.y_offset - (int)g->draw.y_offset)
		* TILE_SIZE;
}

// Stick the camera to the player and offset if the player is over
// the boundaries of the map.
void	update_camera(t_game *g)
{
	update_cam_data(g);
	clamp_cam(g);
	map_offset(g);
}
