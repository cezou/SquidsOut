/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squids_out.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:58:17 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 10:54:17 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUIDS_OUT_H
# define SQUIDS_OUT_H

# include "minisquidx/minisquidx.h"

# define W_LIMIT 200
# define H_LIMIT 100
# define S_SIZE 32

// typedef struct s_player
// {
// 	t_v2f		pos;
// }				t_player;

/* FUNCTIONS */
/* 	Game & Mlx Handling */

void		init_game(t_game *g);
void		init_data(t_game *g);
void		init_window(t_game *g);

/* Check and Init Map */

typedef struct s_map_data
{
	bool	**map;
	char	**char_map;
	size_t	x;
	size_t	y;
	bool	found_it;
}			t_map_data;

void		handle_map(const char *file, t_game *g);
char		**create_map(const char *filename, t_game *g);
bool		is_map_valid(char **map);
bool		is_there_unvalid_chars(char **map);
void		it_contains_everything(char **map, bool *valid);
bool		is_path_valid(char **map);
bool		**turn_map_into_bool(char **map);
void		reset_bool_map(bool **bool_map, char **map);
size_t		*player_starting_position(char **map);

void		print_bool_a(bool **map, char **chars);
size_t		a_len(char **array);

/* [Cezou|cviegas]'s 2D Platformer Engine */

/* Update */

int			update(t_game *g);
void		update_camera(t_game *g);

/* 	Events */

void		events(t_game *g);
int			key_events(int keysym, t_game *g);

// enum
// {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_MOUSEDOWN = 4,
// 	ON_MOUSEUP = 5,
// 	ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17
// };

#endif