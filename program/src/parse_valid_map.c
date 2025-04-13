/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:14:53 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 21:47:00 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(char *line)
{
	char	*p;

	p = line;
	while (*p)
	{
		if (*p != '1' && !ft_isspace(*p))
			return (0);
		p++;
	}
	return (1);
}

int	check_all_sides(char **pos, int j)
{
	if (ft_isspace(pos[-1][j]) || !pos[-1][j])
		return (0);
	if (ft_isspace(pos[0][j - 1]) || !pos[0][j - 1])
		return (0);
	if (ft_isspace(pos[0][j + 1]) || !pos[0][j + 1])
		return (0);
	if (ft_isspace(pos[1][j]) || !pos[1][j])
		return (0);
	return (1);
}

int	is_surround(char **pos)
{
	int	j;

	j = 0;
	if (pos[0][j] == '0' || pos[0][j] == 'N' || pos[0][j] == 'E' ||
		pos[0][j] == 'W' || pos[0][j] == 'S')
		return (0);
	while (pos[0][j])
	{
		if (ft_strchr("0NWES", pos[0][j]))
		{
			if (!check_all_sides(pos, j))
				return (0);
		}
		j++;
	}
	return (1);
}

static int	set_err(t_cub *file_data, const char *msg)
{
	file_data->err_msg = ft_strdup(msg);
	if (!file_data->err_msg)
		ft_exit(file_data, "valid_map(): ", 12);
	return (0);
}

int	valid_map(t_cub *data, char **map)
{
	int		i;
	char	**p;

	i = 0;
	p = map;
	while (p[i] != NULL)
	{
		if ((i == 0 || i == (data->map_h - 1)) && !is_wall(p[i]))
		{
			if (i == 0)
				return (set_err(data, "Map error: First line is not a wall: "));
			else
				return (set_err(data, "Map error: Last line is not a wall: "));
		}
		else
		{
			if (!is_surround(&p[i]))
				return (set_err(data,
						"Map error: map not surround by walls/space in map: "));
		}
		i++;
	}
	return (1);
}
