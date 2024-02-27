/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/27 17:14:02 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

static int	press(int keysym, t_game *g)
{
	// printf("Key pressed: %d\n", keysym);
	g->k[keysym] = true;
	return (0);
}

static int	release(int keysym, t_game *g)
{
	// printf("Key pressed: %d\n", keysym);
	g->k[keysym] = false;
	return (0);
}

void	hooks(t_game *g)
{
	mlx_hook(g->mlx_win, KeyPress, KeyPressMask, press, g);
	// Je veux que ca soit smooth, donc si je reste appuye sur une touche,
	// je veux que ca bouge
	mlx_hook(g->mlx_win, KeyRelease, KeyReleaseMask, release, g);
	mlx_hook(g->mlx_win, DestroyNotify, StructureNotifyMask, exit_game, g);
	mlx_loop_hook(g->mlx, update, g);
}

// mlx_hook(m->mlx_win, ButtonPress, ButtonPressMask, mouse_hook, m);
