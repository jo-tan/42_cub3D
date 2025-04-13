/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:40:07 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/10 18:25:33 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_ptr_to_info_one(char *line)
{
	int	len;

	len = 0;
	while (ft_isspace(line[len]))
		len++;
	while (line[len])
	{
		if (line[len] != 'C' && line[len] != 'F')
		{
			len += 2;
			break ;
		}
		if (line[len] == 'C' || line[len] == 'F')
		{
			len++;
			break ;
		}
	}
	while (ft_isspace(line[len]))
	len++;
	return (len);
}

void	store_path_info(t_cub *file_data, char **txt, char *line)
{
	char	*p;
	size_t	len;

	if (*txt != NULL)
		ft_exit(file_data, "Parsing: find duplicate texture info: ", 0);
	p = line + move_ptr_to_info_one(line);
	len = 0;
	if (ft_strncmp(p, "./", 2) != 0)
	{
		report_err_line(file_data, file_data->line_nbr);
		ft_exit(file_data, file_data->err_msg, 0);
	}
	while (p[len] && !ft_isspace(p[len]))
		len++;
	*txt = ft_strndup(p, len);
	if (!(*txt))
		ft_exit(file_data, "store_path_info(): ", 12);
	if (!is_empty(p + len))
	{
		report_err_line(file_data, file_data->line_nbr);
		ft_exit(file_data, file_data->err_msg, 0);
	}
}

void	store_info(t_cub *file_data, char *line)
{
	if (is_right_info(line) == 1)
		store_path_info(file_data, &file_data->no_txt, line);
	if (is_right_info(line) == 2)
		store_path_info(file_data, &file_data->ea_txt, line);
	if (is_right_info(line) == 3)
		store_path_info(file_data, &file_data->we_txt, line);
	if (is_right_info(line) == 4)
		store_path_info(file_data, &file_data->so_txt, line);
	if (is_right_info(line) == 5)
		store_rgb_info(file_data, &file_data->c_rgb, line);
	if (is_right_info(line) == 6)
		store_rgb_info(file_data, &file_data->f_rgb, line);
}

int	is_right_info(char *line)
{
	char	*p;

	p = line;
	while (*p)
	{
		if (ft_isspace(*p))
			p++;
		else if (ft_strncmp(p, "NO", 2) == 0 && ft_isspace(*(p + 2)))
			return (1);
		else if (ft_strncmp(p, "EA", 2) == 0 && ft_isspace(*(p + 2)))
			return (2);
		else if (ft_strncmp(p, "WE", 2) == 0 && ft_isspace(*(p + 2)))
			return (3);
		else if (ft_strncmp(p, "SO", 2) == 0 && ft_isspace(*(p + 2)))
			return (4);
		else if (ft_strncmp(p, "C", 1) == 0 && ft_isspace(*(p + 1)))
			return (5);
		else if (ft_strncmp(p, "F", 1) == 0 && ft_isspace(*(p + 1)))
			return (6);
		else
			return (0);
	}
	return (0);
}
