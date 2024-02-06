/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:38:25 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/06 11:29:50 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

static bool	isnt_ber_ended(const char *s)
{
	int	i;

	if (ft_strlen(s) < 4)
		return (1);
	i = ft_strlen(s) - 1;
	if (s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.')
		return (0);
	return (1);
}

void	handle_map(const char *file, t_game *g)
{
	if (isnt_ber_ended(file))
		return (merr("File is not a .ber"), free_game(g), exit(FAIL));
	g->map.block = create_map(file, g);
	if (!g->map.block)
		return (free_game(g), exit(FAIL));
	if (!is_map_valid(g->map.block))
		return (free_game(g), exit(FAIL));
}
