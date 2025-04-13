/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:25:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 21:26:11 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rot_left(t_cub *c)
{
	c->old_dirx = c->pl.dir_x;
	c->old_planex = c->plane_x;
	c->pl.dir_x = c->pl.dir_x * cos(-ROT_SPEED) - c->pl.dir_y
		* sin(-ROT_SPEED);
	c->pl.dir_y = c->old_dirx * sin(-ROT_SPEED) + c->pl.dir_y
		* cos(-ROT_SPEED);
	c->plane_x = c->plane_x * cos(-ROT_SPEED) - c->plane_y
		* sin(-ROT_SPEED);
	c->plane_y = c->old_planex * sin(-ROT_SPEED) + c->plane_y
		* cos(-ROT_SPEED);
	rerender(c);
	return (EXIT_SUCCESS);
}

int	rot_right(t_cub *c)
{
	c->old_dirx = c->pl.dir_x;
	c->old_planex = c->plane_x;
	c->pl.dir_x = c->pl.dir_x * cos(ROT_SPEED) - c->pl.dir_y
		* sin(ROT_SPEED);
	c->pl.dir_y = c->old_dirx * sin(ROT_SPEED) + c->pl.dir_y
		* cos(ROT_SPEED);
	c->plane_x = c->plane_x * cos(ROT_SPEED) - c->plane_y
		* sin(ROT_SPEED);
	c->plane_y = c->old_planex * sin(ROT_SPEED) + c->plane_y
		* cos(ROT_SPEED);
	rerender(c);
	return (EXIT_SUCCESS);
}
