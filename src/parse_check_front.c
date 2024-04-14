/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:06:43 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/10 17:37:59 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_loop(t_cub *data, t_list *list, int *counter, int *info_stored)
{
	t_node	*p;

	p = list->head->next;
	while (p != NULL)
	{
		if (is_empty(p->content))
			p = p->next;
		else if (is_right_info(p->content))
		{
			data->line_nbr = *counter;
			store_info(data, p->content);
			(*info_stored)++;
			p = p->next;
		}
		else if (is_map(p->content))
			break ;
		else
		{
			data->line_nbr = *counter;
			report_err_line(data, data->line_nbr);
			return (0);
		}
		(*counter)++;
	}
	return (1);
}

int	check_front(t_cub *file_data, t_list *list)
{
	int		line_counter;
	int		info_stored;

	line_counter = 1;
	info_stored = 0;
	if (!check_loop(file_data, list, &line_counter, &info_stored))
		return (0);
	if (line_counter < 6 || info_stored < 6)
		ft_exit(file_data, "Parsing: Missing texture info: ", 0);
	return (1);
}
