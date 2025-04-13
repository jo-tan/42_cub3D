/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:45:17 by vberard           #+#    #+#             */
/*   Updated: 2024/04/11 18:47:25 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part6(t_cub *c)
{
	while (c->r_y < SH)
	{
		c->tex_y = (int)c->tex_pos & (c->tex->height - 1);
		c->tex_pos += c->step;
		c->color = get_pixel_color(c->tex, c->tex->width
				- c->tex_x - 1, c->tex_y);
		if (c->r_y >= c->offset && c->r_y < (c->offset + c->r.line_height))
			safe_mlx_pixel_put(c, c->r_x, c->r_y, c->color);
		else if (c->r_y < SH / 2)
			safe_mlx_pixel_put(c, c->r_x, c->r_y, c->c_rgb);
		else
			safe_mlx_pixel_put(c, c->r_x, c->r_y, c->f_rgb);
		c->r_y++;
	}
}

void	raycast(t_cub *c)
{
	c->r_x = 0;
	while (c->r_x < SW)
	{
		part1(c);
		part2(c);
		part3(c);
		c->r.line_height = (int)(SH / c->r.perp_walldist);
		c->r_y = 0;
		c->offset = (SH - c->r.line_height) / 2;
		part4(c);
		part5(c);
		part6(c);
		c->r_x++;
	}
}

void	game(t_cub *c)
{
	init_ply(c);
	c->ct = 0;
	c->ot = 0;
	c->mlx = mlx_init();
	ft_init_txt(c);
	c->mlx_win = mlx_new_window(c->mlx, SW, SH, "cub3d");
	c->img.img = mlx_new_image(c->mlx, SW, SH);
	c->img.addr = mlx_get_data_addr(c->img.img, &c->img.bits_per_pixel,
			&c->img.line_length,
			&c->img.endian);
	rerender(c);
	loop(c);
}
