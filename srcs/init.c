/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:37:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/12 19:26:12 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	init_game(t_game *g)
{
	g->spr = malloc(sizeof(t_sprites));
	if (!g->spr)
		return (exit(FAIL));
	g->spr->bg.img = NULL;
	g->map.block = NU;
	g->map.p.pos = (t_v2i){0, 0};
	g->mlx_win = NU;
	g->mlx = NU;
}

static t_img	init_img(t_game *g, const char *path)
{
	t_img	image;

	image.img = mlx_xpm_file_to_image(g->mlx, (char *)path, &image.width,
			&image.height);
	if (!image.img)
		clean_and_exit_game(g, FAIL);
	return (image);
}

void	init_window(t_game *g)
{
	g->spr->bg = init_img(g, "textures/bg.xpm");
	g->mlx_win = mlx_new_window(g->mlx, W_WIDTH, W_HEIGHT, "Squids Out");
	if (!g->mlx_win)
		clean_and_exit_game(g, FAIL);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->spr->bg.img, 0, 0);
}
