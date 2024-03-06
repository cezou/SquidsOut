/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:49:00 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 11:35:25 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	draw_infos(t_game *g)
{
	char	*x;
	char	*y;
	char	*xplusy;

	mlx_string_put(g->mlx, g->mlx_win, 48, 48, 0xFFFFFF, "Traveled");
	xplusy = ft_itoa((int)(g->tiles_traveled[0] + g->tiles_traveled[1]));
	if (!xplusy)
		(perr("Itoa's Malloc Failed"), clean_and_exit_game(g, 1));
	x = ft_itoa((int)g->tiles_traveled[0]);
	if (!x)
		(perr("Itoa's Malloc Failed"), free(xplusy), clean_and_exit_game(g, 1));
	y = ft_itoa((int)g->tiles_traveled[1]);
	if (!y)
		(perr("Itoa's Malloc Failed"), free(xplusy), free(x),
			clean_and_exit_game(g, 1));
	mlx_string_put(g->mlx, g->mlx_win, 100, 48, 0xFFFFFF, xplusy);
	mlx_string_put(g->mlx, g->mlx_win, 48, 64, 0xFFFFFF, "X:");
	mlx_string_put(g->mlx, g->mlx_win, 64, 64, 0xFFFFFF, x);
	mlx_string_put(g->mlx, g->mlx_win, 48, 80, 0xFFFFFF, "Y:");
	mlx_string_put(g->mlx, g->mlx_win, 64, 80, 0xFFFFFF, y);
	free(xplusy);
	free(x);
	free(y);
}

void	events(t_game *g)
{
	p_movements(g);
	collisions(g);
	escape(g);
}

void	update_game_data(t_game *g)
{
	update_elapsed_time(g);
	events(g);
	update_camera(g);
}

void	update_screen(t_game *g)
{
	update_game_data(g);
	draw_map(g);
	draw_player(g);
}

int	update(t_game *g)
{
	update_screen(g);
	print_screen(g);
	draw_infos(g);
	return (0);
}
