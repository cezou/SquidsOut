/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisquidx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/26 18:11:11 by cviegas          ###   ########.fr       */
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

// Redefine les couleurs mais avec ce format "(t_color)0xFF000000"

# define BLACK (t_color)(0xFF000000)
# define WHITE (t_color)(0xFFFFFFFF)
# define RED (t_color)(0xFF0000FF)
# define GREEN (t_color)(0xFF00FF00)
# define BLUE (t_color)(0xFFFF0000)
# define YELLOW (t_color)(0xFF00FFFF)
# define CYAN (t_color)(0xFFFFFF00)
# define MAGENTA (t_color)(0xFFFF00FF)
# define ORANGE (t_color)(0xFF00A5FF)
# define PURPLE (t_color)(0xFF800080)
# define PINK (t_color)(0xFFC71585)
# define BROWN (t_color)(0xFFA52A2A)
# define GREY (t_color)(0xFF808080)
# define LIGHT_GREY (t_color)(0xFFD3D3D3)
# define DARK_GREY (t_color)(0xFFA9A9A9)
# define LIGHT_BLUE (t_color)(0xFFADD8E6)
# define LIGHT_GREEN (t_color)(0xFF90EE90)
# define LIGHT_YELLOW (t_color)(0xFFFFFFE0)
# define LIGHT_CYAN (t_color)(0xFFE0FFFF)
# define LIGHT_MAGENTA (t_color)(0xFFF08080)
# define LIGHT_ORANGE (t_color)(0xFF20B2AA)
# define LIGHT_PURPLE (t_color)(0xFF9370DB)
# define LIGHT_PINK (t_color)(0xFFFFA07A)
# define LIGHT_BROWN (t_color)(0xFFCD853F)
# define DARK_BLUE (t_color)(0xFF00008B)
# define DARK_GREEN (t_color)(0xFF006400)
# define DARK_YELLOW (t_color)(0xFF8B0000)
# define DARK_CYAN (t_color)(0xFF8B8B00)
# define DARK_MAGENTA (t_color)(0xFF8B008B)
# define DARK_ORANGE (t_color)(0xFF008B8B)
# define DARK_PURPLE (t_color)(0xFF4B0082)
# define DARK_PINK (t_color)(0xFF8B5F65)
# define DARK_BROWN (t_color)(0xFF8B4513)

/* Structures */

// Unsigned char is perfect for colors, since it's 0-255.
typedef __uint8_t		t_hexa;
typedef union u_color	t_color;

union					u_color
{
	__uint32_t			integer;
	struct
	{
		__uint8_t		r;
		__uint8_t		g;
		__uint8_t		b;
		__uint8_t		a;
	};
};

typedef struct s_img
{
	void				*img;
	t_color				*pixels;
	t_v2i				size;
}						t_img;

// Here you need to put your own images.
typedef struct s_sprites
{
	t_img				*bg;
	t_img				*block;
	t_img				*player;
	t_img				**squids;
	t_img				*cage;
}						t_sprites;

typedef struct s_map
{
	char				**block;
	size_t				width;
	size_t				height;
	size_t				x_p_pos;
	size_t				y_p_pos;
}						t_map;

typedef struct s_draw
{
	t_sprites			*spr;
	size_t				x_visible_tiles;
	size_t				y_visible_tiles;
	float				x_cam_pos;
	float				y_cam_pos;
	float				x_offset;
	float				y_offset;
}						t_draw;

typedef struct s_game
{
	t_img				*screen;
	void				*mlx;
	void				*mlx_win;
	t_map				map;
	t_draw				draw;
}						t_game;

/* Game Handling */

void					free_game(t_game *g);
int						exit_game(t_game *g);
int						clean_and_exit_game(t_game *g, bool fail);

/* Map Handling */

char					get_tile(size_t x, size_t y, t_game g);
void					set_tile(size_t x, size_t y, char c, t_game *g);

/* Drawing */

t_img					*init_xpm(const char *path, t_game *g);

t_color					get_color(t_img img, t_v2i pos);
void					draw_color(t_color color, t_v2i pos, t_game *g);
void					draw_img(t_img *img, t_v2i pos, t_game *g);
void					draw_square(t_color color, int x, int y, t_game *g);
void					print_pixel(t_color color, t_v2i pos, t_game *g);
void					print_screen(t_game *g);

int						rgb(unsigned char r, unsigned char g, unsigned char b);
bool					draw_tile(char c, size_t x, size_t y, t_game *g);
void					draw_map(t_game *g);
void					draw_player(t_game *g);

/* Utils */

void					merr(const char *s);
void					p_free(void *p);
void					pa_free(void **p);
void					free_img(t_img *img, void *mlx);
void					free_a_img(t_img **img, void *mlx);

#endif