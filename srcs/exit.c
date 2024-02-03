/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:40:31 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/03 17:11:46 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	free_game(t_game *g)
{
	if (g->map.block)
		free_s(g->map.block);
}

int	clean_and_exit_game(t_game *g, bool fail)
{
	mlx_destroy_image(g->mlx, g->spr->bg.img);
	mlx_destroy_window(g->mlx, g->mlx_win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	if (!fail)
		exit(SUCCESS);
	else
		exit(FAIL);
}

int	exit_game(t_game *g)
{
	return (clean_and_exit_game(g, EXIT_SUCCESS));
}
