/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:56:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/06 11:40:52 by cviegas          ###   ########.fr       */
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
	g.mlx = mlx_init();
	if (!g.mlx)
		return (perr("Mlx init failed"), free_game(&g), FAIL);
	init_window(&g);
	events(&g);
	mlx_loop(g.mlx);
	free_game(&g);
	(void)av;
}
