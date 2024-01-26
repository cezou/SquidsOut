/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:31:59 by cviegas           #+#    #+#             */
/*   Updated: 2023/12/04 17:07:01 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MIN_MAX_H
# define FT_MIN_MAX_H
# include <stdarg.h>
# include <unistd.h>

int	ft_bmin(int a, int b);
int	ft_bmax(int a, int b);
int	ft_max(int number, ...);
int	ft_min(int number, ...);

#endif