/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:56:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 12:52:42 by cviegas          ###   ########.fr       */
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
	init_data(&g);
	g.mlx = mlx_init();
	if (!g.mlx)
		return (perr("Mlx init failed"), clean_and_exit_game(&g, 1), FAIL);
	init_window(&g);
	hooks(&g);
	print_map(&g);
	mlx_loop(g.mlx);
}
