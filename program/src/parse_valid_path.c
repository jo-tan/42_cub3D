/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:19:56 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 04:39:46 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_map_empty_line(t_node *p)
{
	t_node	*tmp;

	tmp = p;
	while (tmp != NULL)
	{
		if (is_empty(tmp->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	move_on_paths(int x, int y, char **map_cpy)
{
	char	type;

	type = map_cpy[y][x];
	if (type == '0' || type == 'N' || type == 'S'
		|| type == 'W' || type == 'E')
		map_cpy[y][x] = '1';
	else
		return ;
	move_on_paths(x + 1, y, map_cpy);
	move_on_paths(x - 1, y, map_cpy);
	move_on_paths(x, y + 1, map_cpy);
	move_on_paths(x, y - 1, map_cpy);
}

char	**duplicate_array(t_cub *file_data, char **array)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * (file_data->map_h + 1));
	if (!cpy)
		ft_exit(file_data, "duplicate_array(): ", 12);
	i = 0;
	while (array[i] != NULL)
	{
		cpy[i] = ft_strdup(array[i]);
		if (!cpy[i])
		{
			free_array(cpy);
			ft_exit(file_data, "duplicate_array(): ", 12);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	valid_path(t_cub *file_data)
{
	char	**dup;
	char	**p;
	int		i;

	dup = duplicate_array(file_data, file_data->map);
	if (!dup)
		ft_exit(file_data, "valid_path(): ", 12);
	move_on_paths(file_data->p_x, file_data->p_y, dup);
	p = dup;
	i = 0;
	while (p[i] != NULL)
	{
		if (!is_wall(p[i]))
		{
			report_err_path(file_data, i + 1);
			return (free_array(dup), 0);
		}
		i++;
	}
	return (free_array(dup), 1);
}
