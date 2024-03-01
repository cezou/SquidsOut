/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/01 11:19:52 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	hooks(t_game *g)
{
	mlx_hook(g->mlx_win, KeyPress, KeyPressMask, k_press, g);
	mlx_hook(g->mlx_win, KeyRelease, KeyReleaseMask, k_release, g);
	// mlx_hook(g->mlx_win, ButtonPress, ButtonPressMask, m_press, g);
	// mlx_hook(g->mlx_win, ButtonRelease, ButtonReleaseMask, m_release, g);
	mlx_hook(g->mlx_win, DestroyNotify, StructureNotifyMask, exit_game, g);
	mlx_loop_hook(g->mlx, update, g);
}
