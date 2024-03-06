/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:20:26 by cviegas           #+#    #+#             */
/*   Updated: 2024/03/06 11:48:06 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// I stole these structures from @alde-fre:
// https://profile.intra.42.fr/users/alde-fre
// https://github.com/ForAbby-X
// Go check his work, he did the best so_long and the best cub3d of the world.

#ifndef VEC2_H
# define VEC2_H

# define _USE_MATH_DEFINES
# include <math.h>

typedef float			t_v2f __attribute__((vector_size (8)));
typedef unsigned int	t_v2u __attribute__((vector_size (8)));
typedef int				t_v2i __attribute__((vector_size (8)));

#endif