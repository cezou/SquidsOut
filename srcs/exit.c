/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:40:31 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/30 17:40:39 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

int	clean_and_exit_game(t_mlx *m, bool fail)
{
	mlx_destroy_image(m->mlx, m->game.spr.bg.img);
	mlx_destroy_window(m->mlx, m->mlx_win);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	if (!fail)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

int	exit_game(t_mlx *m)
{
	return (clean_and_exit_game(m, EXIT_SUCCESS));
}