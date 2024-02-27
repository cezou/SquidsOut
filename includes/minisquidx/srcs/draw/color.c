/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:28:32 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/26 18:11:37 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

// Encode RGB values into an integer
int	rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}
