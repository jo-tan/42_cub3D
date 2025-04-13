/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:53:33 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/10 17:10:03 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part1(t_cub *c)
{
	c->pl.cam_x = 2 * c->r_x / (double)SW - 1;
	c->r.ray_dirx = c->pl.dir_x + c->plane_x * c->pl.cam_x;
	c->r.ray_diry = c->pl.dir_y + c->plane_y * c->pl.cam_x;
	c->pl.map_x = (int)c->pl.pos_x;
	c->pl.map_y = (int)c->pl.pos_y;
	if (c->r.ray_dirx == 0)
		c->r.delta_distx = 1e30;
	else
		c->r.delta_distx = fabs(1 / c->r.ray_dirx);
	if (c->r.ray_diry == 0)
		c->r.delta_disty = 1e30;
	else
		c->r.delta_disty = fabs(1 / c->r.ray_diry);
	c->r.hit = 0;
}

void	part2(t_cub *c)
{
	if (c->r.ray_dirx < 0)
	{
		c->r.step_x = -1;
		c->r.side_distx = (c->pl.pos_x - c->pl.map_x)
			* c->r.delta_distx;
	}
	else
	{
		c->r.step_x = 1;
		c->r.side_distx = (c->pl.map_x + 1.0 - c->pl.pos_x)
			* c->r.delta_distx;
	}
	if (c->r.ray_diry < 0)
	{
		c->r.step_y = -1;
		c->r.side_disty = (c->pl.pos_y - c->pl.map_y)
			* c->r.delta_disty;
	}
	else
	{
		c->r.step_y = 1;
		c->r.side_disty = (c->pl.map_y + 1.0 - c->pl.pos_y)
			* c->r.delta_disty;
	}
}

void	part3(t_cub *c)
{
	while (c->r.hit == 0)
	{
		if (c->r.side_distx < c->r.side_disty)
		{
			c->r.side_distx += c->r.delta_distx;
			c->pl.map_x += c->r.step_x;
			c->r.side = 0;
		}
		else
		{
			c->r.side_disty += c->r.delta_disty;
			c->pl.map_y += c->r.step_y;
			c->r.side = 1;
		}
		if (c->map[c->pl.map_y][c->pl.map_x] == '1')
			c->r.hit = 1;
	}
	if (c->r.side == 0)
		c->r.perp_walldist = (c->r.side_distx - c->r.delta_distx);
	else
		c->r.perp_walldist = (c->r.side_disty - c->r.delta_disty);
}

void	part4(t_cub *c)
{
	if (c->r.side == 0)
		c->wall_x = c->pl.pos_y + c->r.perp_walldist * c->r.ray_diry;
	else
		c->wall_x = c->pl.pos_x + c->r.perp_walldist * c->r.ray_dirx;
	c->wall_x -= floor(c->wall_x);
	if (c->r.side == 0)
	{
		if (c->r.ray_dirx > 0)
			c->tex = &c->eatxt;
		else
			c->tex = &c->wetxt;
	}
	else
	{
		if (c->r.ray_diry > 0)
			c->tex = &c->sotxt;
		else
			c->tex = &c->notxt;
	}
}

void	part5(t_cub *c)
{
	c->tex_x = (int)(c->wall_x * (double)(c->tex->width));
	if ((c->r.side == 0 && c->r.ray_dirx > 0)
		|| (c->r.side == 1 && c->r.ray_diry < 0))
		c->tex_x = c->tex->width - c->tex_x - 1;
	c->step = 1.0 * c->tex->height / c->r.line_height;
	c->tex_pos = ((c->offset - SH / 2 + c->r.line_height / 2) * c->step);
	if (c->tex_pos < 0)
		c->tex_pos = 0;
	c->tex_pos = (c->tex_pos * c->tex->height)
		- ((SH - c->r.line_height) / 2) * c->step;
	if (c->tex_pos < 0)
		c->tex_pos += c->tex->height;
}
