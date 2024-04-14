/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:48:20 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:49:06 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*List include dummy head to avoid special cases.
Pointer is started after the dummy head*/
int	ft_dlst_lstsize(t_list *list)
{
	int		size;
	t_node	*p;

	if (!list || !list->head)
		return (0);
	size = 0;
	p = list->head->next;
	while (p)
	{
		size++;
		p = p->next;
	}
	return (size);
}
