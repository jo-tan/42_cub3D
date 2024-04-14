/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:53:17 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 01:03:23 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_txt(t_data txt)
{
	txt.img = NULL;
	txt.addr = NULL;
	txt.bits_per_pixel = 0;
	txt.line_length = 0;
	txt.endian = 0;
	txt.width = 0;
	txt.height = 0;
}

static void	init1(t_cub *file_data)
{
	file_data->raw_cpy = NULL;
	file_data->err_msg = NULL;
	file_data->line_nbr = 0;
	file_data->plyr = '\0';
	file_data->p_x = -1;
	file_data->p_y = -1;
	file_data->no_txt = NULL;
	init_txt(file_data->notxt);
	file_data->so_txt = NULL;
	init_txt(file_data->sotxt);
	file_data->ea_txt = NULL;
	init_txt(file_data->eatxt);
	file_data->we_txt = NULL;
	init_txt(file_data->wetxt);
	file_data->f_rgb = -1;
	file_data->c_rgb = -1;
	file_data->map = NULL;
	file_data->map_w = 0;
	file_data->map_h = 0;
}

void	init_cub_info(t_cub *file_data)
{
	init1(file_data);
	file_data->mlx = 0;
	file_data->mlx_win = 0;
	init_txt(file_data->img);
}

void	init(char *cubfile)
{
	t_cub	*file_data;

	file_data = malloc(sizeof(*file_data));
	if (!file_data)
		ft_exit(NULL, "init(): ", 12);
	init_cub_info(file_data);
	if (!store_file_data(file_data, cubfile))
		ft_exit(file_data, "Parsing failure: read_copy_file() ", 0);
	game(file_data);
}
