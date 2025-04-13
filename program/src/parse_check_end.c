/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:55:28 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 19:59:23 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(char *line)
{
	char	*p;

	p = line;
	while (*p)
	{
		if (*p != '1' && *p != '0' && !ft_isspace(*p))
			return (0);
		p++;
	}
	return (1);
}

int	is_empty(char *line)
{
	char	*p;

	p = line;
	while (*p)
	{
		if (!ft_isspace(*p))
			return (0);
		p++;
	}
	return (1);
}

/*Check_end function will check there is no other info after the map.
And delete all the empty lines which is after the map to release some memspace.
If error, return 0, which will go to ft_exit as "Parsing error: ""*/
int	check_end(t_cub *file_data, t_list *list)
{
	t_node	*p;
	t_node	*tmp;

	p = ft_dlst_tolastone(list);
	while (p != NULL)
	{
		tmp = p;
		p = p->pre;
		if (is_empty(tmp->content))
			ft_dlst_deleteone(tmp);
		else if (is_map(tmp->content))
			break ;
		else
		{
			file_data->line_nbr = ft_dlst_lstsize(list);
			report_err_line(file_data, file_data->line_nbr);
			return (0);
		}
	}
	return (1);
}
