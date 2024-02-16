/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:37:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/16 18:00:23 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

static void	get_p_pos(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g->map.block[i])
	{
		j = 0;
		while (g->map.block[i][j])
		{
			if (g->map.block[i][j] == 'P')
			{
				g->map.x_p_pos = j;
				g->draw.x_cam_pos = j;
				g->map.y_p_pos = i;
				g->draw.y_cam_pos = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_data(t_game *g)
{
	get_p_pos(g);
	g->draw.x_visible_tiles = W_WIDTH / g->map.width + 1;
	g->draw.y_visible_tiles = W_HEIGHT / g->map.height + 1;
	g->draw.x_offset = g->draw.x_cam_pos - (float)g->draw.x_visible_tiles / 2;
	g->draw.y_offset = g->draw.y_cam_pos - (float)g->draw.y_visible_tiles / 2;
}

void	init_game(t_game *g)
{
	g->spr = malloc(sizeof(t_sprites));
	if (!g->spr)
		return (exit(FAIL));
	g->spr->bg.img = NULL;
	g->map.block = NU;
	g->map.width = 0;
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
