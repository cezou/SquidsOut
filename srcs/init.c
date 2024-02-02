/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:37:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/01 11:17:35 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

static t_img	init_img(t_mlx *m, const char *path)
{
	t_img	image;

	image.img = mlx_xpm_file_to_image(m->mlx, (char *)path, &image.width,
			&image.height);
	if (!image.img)
		clean_and_exit_game(m, EXIT_FAILURE);
	return (image);
}

void	init_game(t_mlx *m)
{
	m->game.spr.bg = init_img(m, "textures/bg.xpm");
	m->mlx_win = mlx_new_window(m->mlx, W_WIDTH, W_HEIGHT, "Squids Out");
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->game.spr.bg.img, 0, 0);
}
