/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:35:20 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 03:54:54 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	convert1(t_cub *file_data, char *tmp, char **data, int *rgb)
{
	int		num;
	char	**p;

	num = 0;
	p = data;
	while (*p)
	{
		num = ft_atoi(*p);
		if (num < 0 || num > 255)
		{
			free(tmp);
			free_array(data);
			ft_exit(file_data,
				"Parsing: rgb data is not between 0 to 255: ", 0);
		}
		*rgb = (*rgb << 8) | num;
		p++;
	}
}

void	convert_str_to_rgb(t_cub *file_data, char *tmp, int *rgb)
{
	char	**data;

	data = ft_split(tmp, ',');
	if (!data)
	{
		free(tmp);
		ft_exit(file_data, "convert_str_to_rg(): ", 12);
	}
	convert1(file_data, tmp, data, rgb);
	free_array(data);
	free(tmp);
}

void	store_rgb_info(t_cub *file_data, int *rgb, char *line)
{
	char	*p;
	char	*tmp;
	int		len;

	len = 0;
	if (*rgb != -1)
		ft_exit(file_data,
			"Parsing: find duplicate rgb info. Please check cub file: ", 0);
	p = line + move_ptr_to_info_one(line);
	tmp = save_rgb_info(file_data, p, &len);
	if (!is_empty(p + len))
	{
		free(tmp);
		report_err_line(file_data, file_data->line_nbr);
		ft_exit(file_data, file_data->err_msg, 0);
	}
	if (!valid_rgb(tmp))
	{
		free(tmp);
		ft_exit(file_data,
			"Parsing: invalid rgb info. Please check cub file: ", 0);
	}
	convert_str_to_rgb(file_data, tmp, rgb);
}
