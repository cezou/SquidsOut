/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisquidx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:41:46 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 12:00:43 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISQUIDX_H
# define MINISQUIDX_H

/* Includes */
# include "math.h"
# include "minilibx-linux/mlx.h"
# include "quoicoulibft/libft.h"
# include "stdbool.h"
# include "time.h"
# include "vec2.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Constant Value Defines */
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define TILE_SIZE 96
# define NU NULL
# define STDERR STDERR_FILENO
# define FAIL EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS

/* Key Defines */
# define MAX_KEYS 65535
# define MAX_MOUSE 6
# define MOUSE_LEFT 65536
# define MOUSE_RIGHT 65537
# define MOUSE_MIDDLE 65538
# define MOUSE_SCROLL_UP 65539
# define MOUSE_SCROLL_DOWN 65540

/* Print Color codes */
# define BOLD "\033[1m"
# define P_RED "\033[31m"
# define P_GREEN "\033[32m"
# define RESET "\033[0m"
# define CLEAR "\x1b[2J\x1b[H"

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

// Redefine les couleurs mais avec ce format "0xFF000000"

# define BLACK 0xFF000000
# define WHITE (0xFFFFFFFF)
# define RED (0xFF0000FF)
# define GREEN (0xFF00FF00)
# define BLUE (0xFFFF0000)
# define YELLOW (0xFF00FFFF)
# define CYAN (0xFFFFFF00)
# define MAGENTA (0xFFFF00FF)
# define ORANGE (0xFF00A5FF)
# define PURPLE (0xFF800080)
# define PINK (0xFFC71585)
# define BROWN (0xFFA52A2A)
# define GREY (0xFF808080)
# define LIGHT_GREY (0xFFD3D3D3)
# define DARK_GREY (0xFFA9A9A9)
# define LIGHT_BLUE (0xFFADD8E6)
# define LIGHT_GREEN (0xFF90EE90)
# define LIGHT_YELLOW (0xFFFFFFE0)
# define LIGHT_CYAN (0xFFE0FFFF)
# define LIGHT_MAGENTA (0xFFF08080)
# define LIGHT_ORANGE (0xFF20B2AA)
# define LIGHT_PURPLE (0xFF9370DB)
# define LIGHT_PINK (0xFFFFA07A)
# define LIGHT_BROWN (0xFFCD853F)
# define DARK_BLUE (0xFF00008B)
# define DARK_GREEN (0xFF006400)
# define DARK_YELLOW (0xFF8B0000)
# define DARK_CYAN (0xFF8B8B00)
# define DARK_MAGENTA (0xFF8B008B)
# define DARK_ORANGE (0xFF008B8B)
# define DARK_PURPLE (0xFF4B0082)
# define DARK_PINK (0xFF8B5F65)
# define DARK_BROWN (0xFF8B4513)

/* Vectors */
t_v2i					fadd(t_v2f a, t_v2f b);
t_v2i					fsub(t_v2f a, t_v2f b);
t_v2i					i_add_s(t_v2i a, t_v2i b, size_t s);
t_v2f					faddmul(t_v2f a, t_v2f b, float s);

/* Structures */

/* Stopwatch */
typedef struct s_stopwatch
{
	clock_t				start;
	clock_t				time;
	float				elapsed_time;
}						t_stopwatch;

void					start_stopwatch(t_stopwatch *sw);
void					update_stopwatch(t_stopwatch *sw);
clock_t					get_time(t_stopwatch sw);

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
	void				*address;
	t_color				*pixels;
	t_v2i				size;
}						t_img;

typedef struct s_animated_img
{
	t_img				*sprite[9];
	t_stopwatch			time;
	int					frame;
	bool				is_playing;
	bool				direction;
}						t_animated_img;
// Here you need to put your own images.
typedef struct s_sprites
{
	t_img				*bg;
	t_img				*block;
	t_img				*player;
	t_animated_img		p_idle;
	t_img				**squids;
	t_img				*cage;
}						t_sprites;

typedef struct s_map
{
	char				**block;
	size_t				width;
	size_t				height;
}						t_map;

typedef struct s_draw
{
	bool				first_frame;
	t_sprites			*spr;
	t_v2f				p_pos;
	t_v2f				p_new_pos;
	t_v2f				p_vel;
	size_t				x_visible_tiles;
	size_t				y_visible_tiles;
	float				x_cam_pos;
	float				y_cam_pos;
	t_v2f				offset;
	float				x_offset;
	float				y_offset;
	t_v2f				map_offset;
}						t_draw;

typedef struct s_game
{
	bool				collected_all;
	size_t				collected;
	size_t				goal;
	t_v2f				tiles_traveled;
	bool				keys[MAX_KEYS + MAX_MOUSE];
	t_img				*screen;
	void				*mlx;
	void				*mlx_win;
	t_map				map;
	t_draw				draw;
	t_stopwatch			time;
}						t_game;

/* Game Handling */

void					free_game(t_game *g);
int						exit_game(t_game *g);
int						clean_and_exit_game(t_game *g, bool fail);
float					elapsed_time(t_game *g);
void					update_elapsed_time(t_game *g);

/* Map Handling */

char					get_tile(size_t x, size_t y, t_game g);
void					set_tile(size_t x, size_t y, char c, t_game *g);

/* Key Mapping */
int						k_press(int keysym, t_game *g);
int						k_release(int keysym, t_game *g);
int						m_press(int button, t_game *g);
int						m_release(int button, t_game *g);
bool					is_pressed(int key, t_game *g);

/* Drawing */

t_img					*init_screen(t_game *g);
t_img					*init_xpm(const char *path, t_game *g);
t_img					*init_animated_xpm(const char *folder_path,
							size_t file_nb, t_game *g);

t_color					get_color(t_img img, t_v2i pos);
void					draw_color(t_color color, t_v2i pos, t_game *g);
void					draw_img(t_img *img, t_v2i pos, t_game *g);
void					draw_scaled_img(t_img *spr, t_v2i pos, size_t scale,
							t_game *g);
void					draw_square(t_color color, int x, int y, t_game *g);
void					print_screen(t_game *g);

int						rgb(unsigned char r, unsigned char g, unsigned char b);
bool					draw_tile(char c, size_t x, size_t y, t_game *g);
void					draw_map(t_game *g);
void					draw_player(t_game *g);
void					idle_animation(t_game *g, t_sprites *s);
void					draw_infos(t_game *g);

/* Utils */

void					merr(const char *s);
void					p_free(void *p);
void					pa_free(void **p);
void					free_img(t_img *img, void *mlx);
void					free_a_img(t_img **img, void *mlx);

#endif