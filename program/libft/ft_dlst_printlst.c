/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_printlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:41:34 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:42:14 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//display list, but skip the dummy head
void	ft_dlst_printlst(t_list *list)
{
	t_node	*p;

	if (!list)
		return ;
	p = list->head->next;
	while (p != NULL)
	{
		ft_putstr_fd(p->content, 1);
		p = p->next;
	}
}
