/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:25:04 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/01 19:25:06 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minisquidx.h"

void	start_stopwatch(t_stopwatch *sw)
{
	sw->start = clock() / 1000;
}

void	update_stopwatch(t_stopwatch *sw)
{
	sw->time = clock() / 1000 - sw->start;
}

clock_t	get_time(t_stopwatch sw)
{
	return (sw.time);
}

float	elapsed_time(t_game *g)
{
	return (g->time.elapsed_time);
}

void	update_elapsed_time(t_game *g)
{
	clock_t	current_time;

	current_time = clock();
	g->time.elapsed_time = (float)(current_time - g->time.time)
		/ CLOCKS_PER_SEC;
	g->time.time = current_time;
}
