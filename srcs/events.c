/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/04 11:57:30 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/squids_out.h"

void	p_movements_solo(bool left_right[], bool up_down[], t_game *g) {
  if (up_down[0] && up_down[1])
    g->draw.p_vel[1] = 0;
  else if (up_down[0])
    g->draw.p_vel[1] = -SPEED;
  else if (up_down[1])
    g->draw.p_vel[1] = SPEED;
  if (left_right[0] && left_right[1])
    g->draw.p_vel[0] = 0;
  else if (left_right[0])
    g->draw.p_vel[0] = -SPEED;
  else if (left_right[1])
    g->draw.p_vel[0] = SPEED;
}

void	p_movements(t_game *g) {
  bool left_right[2];
  bool up_down[2];

  ft_bzero(left_right, 2);
  ft_bzero(up_down, 2);
  g->draw.p_vel = (t_v2f){0, 0};
  if (is_pressed(XK_w, g) || is_pressed(XK_Up, g) || is_pressed(XK_space, g))
    up_down[0] = true;
  if (is_pressed(XK_s, g) || is_pressed(XK_Down, g))
    up_down[1] = true;
  if (is_pressed(XK_a, g) || is_pressed(XK_Left, g))
    left_right[0] = true;
  if (is_pressed(XK_d, g) || is_pressed(XK_Right, g))
    left_right[1] = true;
  if (left_right[0] && up_down[0])
    g->draw.p_vel = (t_v2f){-SPEED * BOTH, -SPEED * BOTH};
  else if (left_right[0] && up_down[1])
    g->draw.p_vel = (t_v2f){-SPEED * BOTH, SPEED * BOTH};
  else if (left_right[1] && up_down[0])
    g->draw.p_vel = (t_v2f){SPEED * BOTH, -SPEED * BOTH};
  else if (left_right[1] && up_down[1])
    g->draw.p_vel = (t_v2f){SPEED * BOTH, SPEED * BOTH};
  else
    p_movements_solo(left_right, up_down, g);
}

void	escape(t_game *g) {
  if (is_pressed(XK_Escape, g))
    clean_and_exit_game(g, SUCCESS);
}
