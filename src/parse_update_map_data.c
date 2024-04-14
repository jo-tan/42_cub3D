/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_update_map_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:11:04 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 04:42:15 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_map_line(char *line)
{
	char	*p;

	p = line;
	while (*p)
	{
		if (*p != ' ' && *p != '1' && *p != '0' && *p != '\n'
			&& *p != 'N' && *p != 'S' && *p != 'W' && *p != 'E')
			return (0);
		p++;
	}
	return (1);
}

static int	check_rest(char *p)
{
	while (*p)
	{
		p++;
		if (*p == 'N' || *p == 'S' || *p == 'W' || *p == 'E')
			return (2);
	}
	return (1);
}

/*find_plyr:
return 0 when "NSWE" is not found
return 1 when "NSWE" is found, update plyr and p_x
return 2 when plyr is not '\0' represent multiple plyr is found*/
int	find_plyr(t_cub *file_data, char *line)
{
	int		i;
	char	*p;

	i = 0;
	p = line;
	while (p[i])
	{
		if (p[i] == 'N' || p[i] == 'S' || p[i] == 'W' || p[i] == 'E')
		{
			if (file_data->plyr != '\0')
				return (2);
			else
			{
				file_data->plyr = p[i];
				file_data->p_x = i;
				return (check_rest(&p[i]));
			}
		}
		i++;
	}
	return (0);
}

static int	set_err(t_cub *file_data, const char *msg)
{
	file_data->err_msg = ft_strdup(msg);
	if (!file_data->err_msg)
		ft_exit(file_data, "update_map_data(): ", 12);
	return (0);
}

int	update_map_data(t_cub *file_data, t_node *first_node)
{
	t_node	*p;
	int		width;
	int		plyr_res;

	p = first_node;
	while (p != NULL)
	{
		if (!valid_map_line(p->content))
			return (report_err_map(file_data, file_data->map_h), 0);
		width = ft_strlen(p->content);
		if (width > file_data->map_w)
			file_data->map_w = width;
		file_data->map_h++;
		plyr_res = find_plyr(file_data, p->content);
		if (plyr_res == 2)
			return (report_err_plyr(file_data, file_data->map_h), 0);
		else if (plyr_res == 1)
			file_data->p_y = file_data->map_h;
		p = p->next;
	}
	if (file_data->plyr == '\0')
		return (set_err(file_data, "Parsing error: No player in the map: "));
	return (1);
}
