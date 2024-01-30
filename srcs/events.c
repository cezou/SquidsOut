/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/30 17:45:18 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

int	key_events(int keysym, t_mlx *m)
{
	if (keysym == XK_Escape)
		clean_and_exit_game(m, 0);
	return (0);
}
void	events(t_mlx *m)
{
	mlx_hook(m->mlx_win, KeyPress, KeyPressMask, key_events, m);
	// mlx_hook(m->mlx_win, ButtonPress, ButtonPressMask, mouse_hook, m);
	mlx_hook(m->mlx_win, DestroyNotify, StructureNotifyMask, exit_game, m);
}