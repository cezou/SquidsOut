/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:29:11 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 12:00:08 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

t_v2i	fadd(t_v2f a, t_v2f b)
{
	return ((t_v2i){a[0] + b[0], a[1] + b[1]});
}

t_v2i	fsub(t_v2f a, t_v2f b)
{
	return ((t_v2i){(a[0] - b[0]) * TILE_SIZE, (a[1] - b[1]) * TILE_SIZE});
}

t_v2i	i_add_s(t_v2i a, t_v2i b, size_t s)
{
	return ((t_v2i){(a[0] + b[0]) * s - s, (a[1] + b[1]) * s - s});
}

t_v2f	faddmul(t_v2f a, t_v2f b, float s)
{
	return ((t_v2f){a[0] + b[0] * s, a[1] + b[1] * s});
}
