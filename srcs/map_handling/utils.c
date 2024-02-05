/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:38:25 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/05 18:31:51 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/squids_out.h"

void	print_bool_a(bool **map, char **chars)
{
	size_t	i;
	size_t	j;
	char	c;

	c = 'a';
	i = 0;
	while (chars[i])
	{
		j = 0;
		ft_printf("%c: ", c++);
		while (chars[i][j])
		{
			ft_printf("%d", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
size_t	*pos_dup(size_t *pos)
{
	size_t	*dup;

	dup = malloc(sizeof(size_t) * 2);
	if (!dup)
		return (merr("Malloc failed"), NULL);
	dup[0] = pos[0];
	dup[1] = pos[1];
	return (dup);
}

size_t	a_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
