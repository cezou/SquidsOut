/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/01 19:50:46 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	p_movements(t_game *g)
{
	g->draw.p_vel = (t_v2f){0, 0};
	if (is_pressed(XK_w, g) || is_pressed(XK_Up, g) || is_pressed(XK_space, g))
		g->draw.p_vel[1] = -SPEED;
	if (is_pressed(XK_s, g) || is_pressed(XK_Down, g))
		g->draw.p_vel[1] = SPEED;
	if (is_pressed(XK_a, g) || is_pressed(XK_Left, g))
		g->draw.p_vel[0] = -SPEED;
	if (is_pressed(XK_d, g) || is_pressed(XK_Right, g))
		g->draw.p_vel[0] = SPEED;
}

void	escape(t_game *g)
{
	if (is_pressed(XK_Escape, g))
		clean_and_exit_game(g, SUCCESS);
}
