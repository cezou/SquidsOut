/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squids_out.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:58:17 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/02 19:22:01 by cviegas          ###   ########.fr       */
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

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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

typedef struct s_game
{
	t_sprites	spr;
}				t_game;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_game		game;
}				t_mlx;

/* FUNCTIONS */
/* 	Game Handling */
void			init_game(t_mlx *m);
int				clean_and_exit_game(t_mlx *m, bool fail);
int				exit_game(t_mlx *m);

/* 	Events */
void			events(t_mlx *m);
int				key_events(int keysym, t_mlx *m);

/* Map Handling */
void			handle_map(const char *file);

// DEFINE COLORS FOR PRINTF IN STRINGS:
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"
#endif