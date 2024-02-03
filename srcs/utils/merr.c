/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:33:17 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/03 16:54:39 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

/* Similar to my perr function, but starts with "Map: " */
void	merr(const char *s)
{
	ft_printfd(STDERR, "%s%sMap: %s%s\n", BOLD, RED, s, RESET);
}
