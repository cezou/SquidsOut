/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:48:59 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 11:48:26 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

bool	is_pressed(int key, t_game *g)
{
	if (g->keys[key])
		return (1);
	return (0);
}

int	k_press(int keysym, t_game *g)
{
	g->keys[keysym] = true;
	return (0);
}

int	k_release(int keysym, t_game *g)
{
	g->keys[keysym] = false;
	return (0);
}

int	m_press(int button, t_game *g)
{
	g->keys[button] = true;
	return (0);
}

int	m_release(int button, t_game *g)
{
	g->keys[button] = false;
	return (0);
}
