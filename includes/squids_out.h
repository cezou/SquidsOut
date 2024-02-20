/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squids_out.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:58:17 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/20 10:52:44 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUIDS_OUT_H
# define SQUIDS_OUT_H

# include "QuoicouLibft/libft.h"
# include "math.h"
# include "minilibx-linux/mlx.h"
# include "stdbool.h"
# include "vec2.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define W_LIMIT 200
# define H_LIMIT 100
# define S_SIZE 32
# define TILE_SIZE 100
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
	t_img		block;
	t_img		player;
	t_img		*squids;
	t_img		cage;
}				t_sprites;

// typedef struct s_player
// {
// 	t_v2f		pos;
// }				t_player;

typedef struct s_map
{
	char		**block;
	size_t		width;
	size_t		height;
	size_t		x_p_pos;
	size_t		y_p_pos;
}				t_map;

typedef struct s_draw
{
	size_t		x_visible_tiles;
	size_t		y_visible_tiles;
	float		x_cam_pos;
	float		y_cam_pos;
	float		x_offset;
	float		y_offset;
}				t_draw;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_sprites	*spr;
	t_map		map;
	t_draw		draw;
}				t_game;

/* FUNCTIONS */
/* 	Game & Mlx Handling */

void			init_game(t_game *g);
void			init_data(t_game *g);
void			init_window(t_game *g);
int				clean_and_exit_game(t_game *g, bool fail);
void			free_game(t_game *g);
int				exit_game(t_game *g);

/* Check and Init Map */

typedef struct s_map_data
{
	bool		**map;
	char		**char_map;
	size_t		x;
	size_t		y;
	bool		found_it;
}				t_map_data;

void			handle_map(const char *file, t_game *g);
char			**create_map(const char *filename, t_game *g);
bool			is_map_valid(char **map);
bool			is_there_unvalid_chars(char **map);
void			it_contains_everything(char **map, bool *valid);
bool			is_path_valid(char **map);
bool			**turn_map_into_bool(char **map);
void			reset_bool_map(bool **bool_map, char **map);
size_t			*player_starting_position(char **map);

/* Utils */

void			merr(const char *s);
void			protected_free(void *p);
void			protected_a_free(void **p);
void			print_bool_a(bool **map, char **chars);
size_t			a_len(char **array);

/* [Cezou|cviegas]'s 2D Platformer Engine */

/* Update */

int				update(t_game *g);
void			update_camera(t_game *g);

/* 	Events */

void			events(t_game *g);
int				key_events(int keysym, t_game *g);

/* Map Handling */

char			get_tile(size_t x, size_t y, t_game g);
void			set_tile(size_t x, size_t y, char c, t_game *g);

/* Drawing */

t_img			init_xpm(const char *path, t_game *g);
void			put_img(void *img, int x, int y, t_game *g);
int				rgb(unsigned char r, unsigned char g, unsigned char b);
void			put_color(int color, int x, int y, t_game *g);
bool			draw_tile(char c, size_t x, size_t y, t_game *g);
void			draw_map(t_game *g);
void			draw_player(t_game *g);

/* int Color codes */

# undef BLACK
# undef WHITE
# undef RED
# undef GREEN
# undef BLUE
# undef YELLOW
# undef CYAN
# undef MAGENTA
# undef ORANGE
# undef PURPLE
# undef PINK
# undef BROWN
# undef GREY
# undef LIGHT_GREY
# undef DARK_GREY
# undef LIGHT_BLUE
# undef LIGHT_GREEN
# undef LIGHT_YELLOW
# undef LIGHT_CYAN
# undef LIGHT_MAGENTA
# undef LIGHT_ORANGE
# undef LIGHT_PURPLE
# undef LIGHT_PINK
# undef LIGHT_BROWN
# undef DARK_BLUE
# undef DARK_GREEN
# undef DARK_YELLOW
# undef DARK_CYAN
# undef DARK_MAGENTA
# undef DARK_ORANGE
# undef DARK_PURPLE
# undef DARK_PINK
# undef DARK_BROWN

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define PINK 0xFFC0CB
# define BROWN 0xA52A2A
# define GREY 0x808080
# define LIGHT_GREY 0xD3D3D3
# define DARK_GREY 0xA9A9A9
# define LIGHT_BLUE 0xADD8E6
# define LIGHT_GREEN 0x90EE90
# define LIGHT_YELLOW 0xFFFFE0
# define LIGHT_CYAN 0xE0FFFF
# define LIGHT_MAGENTA 0xFFB6C1
# define LIGHT_ORANGE 0xFFD700
# define LIGHT_PURPLE 0x9370DB
# define LIGHT_PINK 0xFFB6C1
# define LIGHT_BROWN 0xCD853F
# define DARK_BLUE 0x00008B
# define DARK_GREEN 0x006400
# define DARK_YELLOW 0x808000
# define DARK_CYAN 0x008080
# define DARK_MAGENTA 0x8B008B
# define DARK_ORANGE 0xFF8C00
# define DARK_PURPLE 0x800080
# define DARK_PINK 0xFF1493
# define DARK_BROWN 0x8B4513

/* Define colors for printf in strings */
# define BOLD "\033[1m"
# define P_RED "\033[31m"
# define P_GREEN "\033[32m"
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