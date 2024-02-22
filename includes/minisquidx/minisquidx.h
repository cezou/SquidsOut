/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisquidx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 13:57:32 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISQUIDX_H
# define MINISQUIDX_H

/* Includes */
# include "math.h"
# include "minilibx-linux/mlx.h"
# include "quoicoulibft/libft.h"
# include "stdbool.h"
# include "vec2.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Constant Value Defines */
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define TILE_SIZE 100
# define NU NULL
# define STDERR STDERR_FILENO
# define FAIL EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS

/* Print Color codes */
# define BOLD "\033[1m"
# define P_RED "\033[31m"
# define P_GREEN "\033[32m"
# define RESET "\033[0m"

/* Int Color codes */
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

/* Structures */

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

// Here you need to put your own images.
typedef struct s_sprites
{
	t_img		bg;
	t_img		block;
	t_img		player;
	t_img		*squids;
	t_img		cage;
}				t_sprites;

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
	t_sprites	*spr;
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
	t_map		map;
	t_draw		draw;
}				t_game;

/* Game Handling */

void			free_game(t_game *g);
int				exit_game(t_game *g);
int				clean_and_exit_game(t_game *g, bool fail);

/* Map Handling */

char			get_tile(size_t x, size_t y, t_game g);
void			set_tile(size_t x, size_t y, char c, t_game *g);

/* Drawing */

t_img			init_xpm(const char *path, t_game *g);
void			put_img(void *img, int x, int y, t_game *g);
int				rgb(unsigned char r, unsigned char g, unsigned char b);
void			put_square(int color, int x, int y, t_game *g);
bool			draw_tile(char c, size_t x, size_t y, t_game *g);
void			draw_map(t_game *g);
void			draw_player(t_game *g);

/* Utils */

void			merr(const char *s);
void			p_free(void *p);
void			pa_free(void **p);
void			free_img(t_img *img, void *mlx);
void			free_a_img(t_img **img, void *mlx);

#endif