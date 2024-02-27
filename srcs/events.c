/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/27 15:58:43 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	p_movements(t_game *g)
{
	if (g->k[XK_w] || g->k[XK_Up] || g->k[XK_space])
		g->draw.p_pos[1] -= SPEED;
	if (g->k[XK_s] || g->k[XK_Down])
		g->draw.p_pos[1] += SPEED;
	if (g->k[XK_a] || g->k[XK_Left])
		g->draw.p_pos[0] -= SPEED;
	if (g->k[XK_d] || g->k[XK_Right])
		g->draw.p_pos[0] += SPEED;
}

void	escape(t_game *g)
{
	if (g->k[XK_Escape])
		clean_and_exit_game(g, SUCCESS);
}
