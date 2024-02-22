/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:33:17 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/22 09:49:16 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minisquidx.h"

/* Similar to my perr function, but starts with "Map: " */
void	merr(const char *s)
{
	ft_printfd(STDERR, "%s%sMap: %s%s%s%s\n", BOLD, P_RED, RESET, P_RED, s,
		RESET);
}
