/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squids_out.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:58:17 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 18:32:40 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUIDS_OUT_H
# define SQUIDS_OUT_H

# include "QuoicouLibft/libft.h"
# include "math.h"
# include "minilibx-linux/mlx.h"
# include "stdbool.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define NU NULL
# define STDERR STDERR_FILENO
# define FAIL EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

typedef struct s_sprites
{
	t_img		bg;
}				t_sprites;

typedef struct s_map
{
	char		**block;
	float		**pos;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_sprites	*spr;
	t_map		map;
}				t_game;

/* FUNCTIONS */
/* 	Game Handling */

void			init_game(t_game *g);
void			init_window(t_game *g);
int				clean_and_exit_game(t_game *g, bool fail);
void			free_game(t_game *g);
int				exit_game(t_game *g);

/* 	Events */

void			events(t_game *g);
int				key_events(int keysym, t_game *g);

/* Map Handling */

void			handle_map(const char *file, t_game *g);
char			**create_map(const char *filename);
bool			is_map_valid(char **map);
bool			is_there_unvalid_chars(char **map);
void			it_contains_everything(char **map, bool *valid);
bool			is_path_valid(char **map);

/* Utils */

void			merr(const char *s);
void			protected_free(void *p);
void			protected_a_free(void **p);
void			print_bool_a(bool **map, char **chars);
size_t			a_len(char **array);
size_t			*pos_dup(size_t *pos);
// DEFINE COLORS FOR PRINTF IN STRINGS:
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

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