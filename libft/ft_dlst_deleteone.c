/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_deleteone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:43:35 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:51:11 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_deleteone(t_node *node)
{
	if (!node)
		return ;
	if (node->next == NULL)
	{
		if (node->pre != NULL)
			node->pre->next = NULL;
	}
	else
	{
		node->next->pre = node->pre;
		if (node->pre != NULL)
			node->pre->next = node->next;
	}
	if (node->content != NULL)
		free(node->content);
	free(node);
}
