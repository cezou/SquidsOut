/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:40:31 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 13:51:44 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minisquidx.h"

static void	destroy_spr(t_game *g)
{
	free_img(&g->draw.spr->bg, g->mlx);
	free_img(&g->draw.spr->block, g->mlx);
	free_img(&g->draw.spr->player, g->mlx);
	free_img(&g->draw.spr->cage, g->mlx);
	p_free(g->draw.spr);
}

void	free_game(t_game *g)
{
	destroy_spr(g);
	pa_free((void **)g->map.block);
}

int	clean_and_exit_game(t_game *g, bool fail)
{
	free_game(g);
	if (g->mlx_win)
		mlx_destroy_window(g->mlx, g->mlx_win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		p_free(g->mlx);
	}
	if (!fail)
		exit(SUCCESS);
	else
		exit(FAIL);
}

int	exit_game(t_game *g)
{
	return (clean_and_exit_game(g, EXIT_SUCCESS));
}
