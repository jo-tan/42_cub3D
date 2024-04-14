/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:39:35 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:53:31 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_dlst_init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = malloc(sizeof(t_node));
	if (!list->head)
	{
		free(list);
		return (NULL);
	}
	list->head->content = NULL;
	list->head->pre = NULL;
	list->head->next = NULL;
	return (list);
}
