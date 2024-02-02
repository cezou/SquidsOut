/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:56:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/02 19:24:37 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

int	main(int ac, char **av)
{
	t_mlx	m;

	if (ac != 2)
		return (perr("Usage: ./so_long mapfile.ber"), EXIT_FAILURE);
	handle_map(av[1]);
	return (0);
	m.mlx = mlx_init();
	init_game(&m);
	events(&m);
	mlx_loop(m.mlx);
	(void)av;
}
