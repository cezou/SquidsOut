/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/03 15:38:00 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

int	key_events(int keysym, t_game *g)
{
	if (keysym == XK_Escape)
		clean_and_exit_game(g, 0);
	return (0);
}

void	events(t_game *g)
{
	mlx_hook(g->mlx_win, KeyPress, KeyPressMask, key_events, g);
	mlx_hook(g->mlx_win, DestroyNotify, StructureNotifyMask, exit_game, g);
}

// mlx_hook(m->mlx_win, ButtonPress, ButtonPressMask, mouse_hook, m);
