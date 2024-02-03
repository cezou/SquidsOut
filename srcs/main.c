/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:56:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/03 15:56:22 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		return (perr("Usage: ./so_long mapfile.ber"), FAIL);
	init_game(&g);
	handle_map(av[1], &g);
	free_game(&g);
	return (0);
	g.mlx = mlx_init();
	init_window(&g);
	events(&g);
	mlx_loop(g.mlx);
}
