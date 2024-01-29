/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:56:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/29 20:03:12 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

int	main(void)
{
	t_mlx	m;

	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, W_WIDTH, W_HEIGHT, "Squids Out");
	mlx_loop(m.mlx);
}
