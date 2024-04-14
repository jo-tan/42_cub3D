/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberard <vberard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:47:23 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 21:27:01 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key, t_cub *c)
{
	if (key == KUP)
		c->move_up = 1;
	else if (key == KDOWN)
		c->move_down = 1;
	else if (key == KLEFT)
		c->rot_left = 1;
	else if (key == KRIGHT)
		c->rot_right = 1;
	else if (key == KEYA)
		c->move_left = 1;
	else if (key == KEYD)
		c->move_right = 1;
	else if (key == ESCAPE)
	{
		ft_close(c);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	ft_key_release(int key, t_cub *c)
{
	if (key == KUP)
		c->move_up = 0;
	else if (key == KDOWN)
		c->move_down = 0;
	else if (key == KLEFT)
		c->rot_left = 0;
	else if (key == KRIGHT)
		c->rot_right = 0;
	else if (key == KEYA)
		c->move_left = 0;
	else if (key == KEYD)
		c->move_right = 0;
	return (EXIT_SUCCESS);
}

void	continuous_movement(t_cub *c)
{
	if (c->move_up)
		move_up(c);
	if (c->move_down)
		move_down(c);
	if (c->move_left)
		move_left(c);
	if (c->move_right)
		move_right(c);
	if (c->rot_left)
		rot_left(c);
	if (c->rot_right)
		rot_right(c);
}

void	hook(t_cub *c)
{
	mlx_hook(c->mlx_win, KeyPress, KeyPressMask, ft_key_press, c);
	mlx_hook(c->mlx_win, KeyRelease, KeyReleaseMask, ft_key_release, c);
	mlx_hook(c->mlx_win, DestroyNotify, StructureNotifyMask, ft_close, c);
}

void	loop(t_cub *c)
{
	mlx_loop_hook(c->mlx, (void *)&continuous_movement, c);
	hook(c);
	mlx_loop(c->mlx);
}
