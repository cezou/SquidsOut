/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:52:14 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 09:49:10 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

/* Frees only if the adress exists and becomes a NULL pointer */
void	p_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

/* Frees any type of double pointer */
static void	a_free(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

/* Same than p_free but for an array of pointers */
void	pa_free(void **p)
{
	if (p)
	{
		a_free(p);
		p = NULL;
	}
}

void	free_img(t_img *img, void *mlx)
{
	if (img && img->img)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
	}
}

void	free_a_img(t_img **img, void *mlx)
{
	size_t	i;

	i = 0;
	while (img[i])
		free_img(img[i++], mlx);
}
