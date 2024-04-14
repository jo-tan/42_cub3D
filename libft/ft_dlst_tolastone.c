/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_tolastone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:40:44 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:41:20 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_dlst_tolastone(t_list *list)
{
	t_node	*p;

	if (!list || !list->head)
		return (NULL);
	p = list->head;
	while (p->next != NULL)
		p = p->next;
	return (p);
}
