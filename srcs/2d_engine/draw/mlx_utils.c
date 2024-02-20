/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:28:32 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/18 23:36:43 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/squids_out.h"

// Init a xmp image FILE in "textures/xpms/${FILE}.xpm" path
t_img	init_xpm(const char *path, t_game *g)
{
	t_img	image;
	char	*in_texture_dir;
	char	*full_path;

	in_texture_dir = ft_strjoin("textures/xpms/", path);
	if (!in_texture_dir)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	full_path = ft_strjoin(in_texture_dir, ".xpm");
	free(in_texture_dir);
	if (!full_path)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	image.img = mlx_xpm_file_to_image(g->mlx, full_path, &image.width,
			&image.height);
	free(full_path);
	if (!image.img)
		clean_and_exit_game(g, FAIL);
	return (image);
}

// Init a png image FILE in "textures/pngs/${FILE}.png" path
// t_img	init_png(const char *path, t_game *g)
// {
// 	t_img	image;
// 	char	*in_texture_dir;
// 	char	*full_path;

// 	in_texture_dir = ft_strjoin("textures/pngs/", path);
// 	if (!in_texture_dir)
// 		(perr("Malloc"), clean_and_exit_game(g, FAIL));
// 	full_path = ft_strjoin(in_texture_dir, ".png");
// 	free(in_texture_dir);
// 	if (!full_path)
// 		(perr("Malloc"), clean_and_exit_game(g, FAIL));
// 	image.img = mlx_png_file_to_image(g->mlx, full_path, &image.width,
// 			&image.height);
// 	free(full_path);
// 	if (!image.img)
// 		clean_and_exit_game(g, FAIL);
// 	return (image);
// }

// Encode RGB values into an integer
int	rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

// Draw a TILE_SIZE colored square
void	put_color(int color, int x, int y, t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(g->mlx, g->mlx_win, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// Function mlx_put_image_to_window but easier
void	put_img(void *img, int x, int y, t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, img, x, y);
}
