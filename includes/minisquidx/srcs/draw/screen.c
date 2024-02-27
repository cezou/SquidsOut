/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:28:32 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/27 18:07:07 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

t_color	get_color(t_img img, t_v2i pos)
{
	if (pos[0] < 0 || pos[0] >= img.size[0] || pos[1] < 0
		|| pos[1] >= img.size[1])
		return (BLACK);
	return (img.pixels[pos[1] * img.size[0] + pos[0]]);
}

void	draw_color(t_color color, t_v2i pos, t_game *g)
{
	if (color.r == 0 && color.g == 0 && color.b == 0)
		return ;
	if (pos[0] < 0 || pos[0] >= g->screen->size[0] || pos[1] < 0
		|| pos[1] >= g->screen->size[1])
		return ;
	((int *)g->screen->address)[pos[1] * g->screen->size[0]
		+ pos[0]] = color.integer;
}

void	print_screen(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->screen->img, 0, 0);
}
