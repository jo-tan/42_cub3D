/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_freelst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:38:05 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:53:06 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_freelst(t_list *list)
{
	t_node	*p;
	t_node	*next;

	if (!list)
		return ;
	p = list->head;
	while (p != NULL)
	{
		if (p->content != NULL)
			free(p->content);
		next = p->next;
		free(p);
		p = next;
	}
	free(list);
}
