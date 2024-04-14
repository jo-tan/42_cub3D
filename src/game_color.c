/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:39:32 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/10 15:43:15 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	safe_mlx_pixel_put(t_cub *c, int x, int y, int color)
{
	if (x < 0 || x >= SW || y < 0 || y >= SH)
		return ;
	my_mlx_pixel_put(&c->img, x, y, color);
}

int	get_pixel_color(t_data *data, int x, int y)
{
	int		bpp;
	char	*pixel;
	int		color;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return (0);
	bpp = data->bits_per_pixel / 8;
	pixel = data->addr + (y * data->line_length + x * bpp);
	color = *(unsigned int *)pixel;
	return (color);
}
