/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_addlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:45:10 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:49:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//add a new node at the end of the list
void	ft_dlst_addlast(t_list *list, char *line)
{
	t_node	*new;
	t_node	*p;

	if (!list || !line)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->content = line;
	new->next = NULL;
	p = list->head;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->pre = p;
}
