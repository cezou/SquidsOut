/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:22:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/06 19:45:08 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!content)
		return (NULL);
	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
