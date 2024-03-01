/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:25:04 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/01 11:40:21 by cviegas          ###   ########.fr       */
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
