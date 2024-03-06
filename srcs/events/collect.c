/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:22:16 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 11:57:30 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

static size_t	find_x_exit(t_game g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g.map.block[i])
	{
		j = 0;
		while (g.map.block[i][j])
		{
			if (g.map.block[i][j] == 'E')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	find_y_exit(t_game g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g.map.block[i])
	{
		j = 0;
		while (g.map.block[i][j])
		{
			if (g.map.block[i][j] == 'E')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	collect(t_game *g)
{
	if (get_tile(g->draw.p_pos[0] + 0.5, g->draw.p_pos[1] + 0.5, *g) == 'C')
	{
		set_tile(g->draw.p_pos[0] + 0.5, g->draw.p_pos[1] + 0.5, '0', g);
		g->collected++;
	}
	(void)g;
	if (g->collected == g->goal && !g->collected_all)
	{
		g->collected_all = 1;
		set_tile(find_x_exit(*g), find_y_exit(*g), 'V', g);
	}
	if (g->collected_all)
	{
		if (get_tile(g->draw.p_pos[0] + 0.5, g->draw.p_pos[1] + 0.5, *g) == 'V')
			(ft_printf("%s%s%s%s%s\n", CLEAR, BOLD, P_GREEN,
					"Congratulations you Won!", RESET), clean_and_exit_game(g,
					0));
	}
}
