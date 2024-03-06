/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:28:32 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 12:57:39 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

// Init the screen (same than xpm but the path is fixed to
// "textures/xpms/screen.xpm" and it also stores the adress)
t_img	*init_screen(t_game *g)
{
	t_img	*image;
	int		trash[2];

	image = malloc(sizeof(t_img));
	if (!image)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	image->img = mlx_xpm_file_to_image(g->mlx, "textures/xpms/screen.xpm",
			&trash[0], &trash[1]);
	if (!image->img)
		return (free(image), clean_and_exit_game(g, FAIL), NULL);
	image->size = (t_v2i){trash[0], trash[1]};
	image->address = mlx_get_data_addr(image->img, &trash[1], &trash[1],
			&trash[1]);
	image->pixels = (t_color *)(t_hexa *)image->address;
	return (image);
}

// Init a xmp image FILE in "textures/xpms/${FILE}.xpm" path
t_img	*init_xpm(const char *path, t_game *g)
{
	t_img	*image;
	char	*in_texture_dir;
	char	*full_path;
	int		trash[2];

	in_texture_dir = ft_strjoin("textures/xpms/", path);
	if (!in_texture_dir)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	full_path = ft_strjoin(in_texture_dir, ".xpm");
	free(in_texture_dir);
	if (!full_path)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	image = malloc(sizeof(t_img));
	if (!image)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	image->img = mlx_xpm_file_to_image(g->mlx, full_path, &trash[0], &trash[1]);
	free(full_path);
	if (!image->img)
		(perr("Image init failed"), free(image), clean_and_exit_game(g, FAIL));
	image->size = (t_v2i){trash[0], trash[1]};
	image->pixels = (t_color *)(t_hexa *)mlx_get_data_addr(image->img,
			&trash[1], &trash[1], &trash[1]);
	return (image);
}

// Init a xmp image FILE in "textures/xpms/${FILE}.xpm" path
t_img	*init_animated_xpm(const char *folder_path, size_t file_nb, t_game *g)
{
	t_img	*image;
	char	*nb;
	char	*full_path;
	int		trash[2];

	nb = ft_itoa(file_nb);
	if (!nb)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	full_path = ft_strjoin_4("textures/xpms/", folder_path, nb, ".xpm");
	free(nb);
	if (!full_path)
		(perr("Malloc"), clean_and_exit_game(g, FAIL));
	image = malloc(sizeof(t_img));
	if (!image)
		(free(full_path), perr("Malloc"), clean_and_exit_game(g, FAIL));
	image->img = mlx_xpm_file_to_image(g->mlx, full_path, &trash[0], &trash[1]);
	free(full_path);
	if (!image->img)
		(free(image), (perr("Image init failed"), clean_and_exit_game(g,
					FAIL)));
	image->size = (t_v2i){trash[0], trash[1]};
	image->pixels = (t_color *)(t_hexa *)mlx_get_data_addr(image->img,
			&trash[1], &trash[1], &trash[1]);
	return (image);
}
