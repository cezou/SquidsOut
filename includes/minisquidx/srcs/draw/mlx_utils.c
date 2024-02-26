/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:28:32 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/26 12:03:59 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

// Init a xmp image FILE in "textures/xpms/${FILE}.xpm" path
t_img	*init_xpm(const char *path, t_game *g)
{
	t_img	*image;
	char	*in_texture_dir;
	char	*full_path;
	int		trash[6];

	image = malloc(sizeof(t_img));
	if (!image)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	in_texture_dir = ft_strjoin("textures/xpms/", path);
	if (!in_texture_dir)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	full_path = ft_strjoin(in_texture_dir, ".xpm");
	free(in_texture_dir);
	if (!full_path)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	perr("SQUID");
	image->img = mlx_xpm_file_to_image(g->mlx, full_path, &trash[0],
			(&trash[1]));
	perr("SQUID");
	free(full_path);
	if (!image->img)
		clean_and_exit_game(g, FAIL);
	perr("SQUID");
	image->pixels = (t_color *)(t_hexa *)mlx_get_data_addr(image->img,
			&trash[2], &trash[3], &trash[4]);
	return (image);
}

// Function mlx_put_image_to_window but easier
void	put_img(void *img, int x, int y, t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, img, x, y);
}
