/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squids_out.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:58:17 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/29 20:01:44 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUIDS_OUT_H
# define SQUIDS_OUT_H

# include "QuoicouLibft/libft.h"
# include "minilibx-linux/mlx.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

#endif