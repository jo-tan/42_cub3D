/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberard <vberard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:25:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 21:26:42 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rerender(t_cub *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	c->img.img = mlx_new_image(c->mlx, SW, SH);
	raycast(c);
	mlx_put_image_to_window(c->mlx, c->mlx_win,
		(&c->img)->img, 0, 0);
}

int	move_up(t_cub *c)
{
	if (c->map[(int)c->pl.pos_y][(int)(c->pl.pos_x
		+ c->pl.dir_x * PL_SPEED)] != '1')
		c->pl.pos_x += c->pl.dir_x * PL_SPEED;
	if (c->map[(int)(c->pl.pos_y
			+ c->pl.dir_y * PL_SPEED)][(int)c->pl.pos_x] != '1')
		c->pl.pos_y += c->pl.dir_y * PL_SPEED;
	rerender(c);
	return (EXIT_SUCCESS);
}

int	move_down(t_cub *c)
{
	if (c->map[(int)c->pl.pos_y][(int)(c->pl.pos_x
		- c->pl.dir_x * PL_SPEED)] != '1')
		c->pl.pos_x -= c->pl.dir_x * PL_SPEED;
	if (c->map[(int)(c->pl.pos_y
			- c->pl.dir_y * PL_SPEED)][(int)c->pl.pos_x] != '1')
		c->pl.pos_y -= c->pl.dir_y * PL_SPEED;
	rerender(c);
	return (EXIT_SUCCESS);
}

int	move_right(t_cub *c)
{
	if (c->map[(int)c->pl.pos_y][(int)(c->pl.pos_x
		- c->pl.dir_y * PL_SPEED)] != '1')
		c->pl.pos_x -= c->pl.dir_y * PL_SPEED;
	if (c->map[(int)(c->pl.pos_y
			+ c->pl.dir_x * PL_SPEED)][(int)c->pl.pos_x] != '1')
		c->pl.pos_y += c->pl.dir_x * PL_SPEED;
	rerender(c);
	return (EXIT_SUCCESS);
}

int	move_left(t_cub *c)
{
	if (c->map[(int)c->pl.pos_y][(int)(c->pl.pos_x
		+ c->pl.dir_y * PL_SPEED)] != '1')
		c->pl.pos_x += c->pl.dir_y * PL_SPEED;
	if (c->map[(int)(c->pl.pos_y
			- c->pl.dir_x * PL_SPEED)][(int)c->pl.pos_x] != '1')
		c->pl.pos_y -= c->pl.dir_x * PL_SPEED;
	rerender(c);
	return (EXIT_SUCCESS);
}
