/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:46:28 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 03:11:22 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	txtinit_close(t_cub *c)
{
	mlx_loop_end(c->mlx);
	if (c->notxt.img)
		mlx_destroy_image(c->mlx, c->notxt.img);
	if (c->sotxt.img)
		mlx_destroy_image(c->mlx, c->sotxt.img);
	if (c->eatxt.img)
		mlx_destroy_image(c->mlx, c->eatxt.img);
	if (c->wetxt.img != NULL)
		mlx_destroy_image(c->mlx, c->wetxt.img);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
	free_cub_data(c);
	exit(1);
	return (0);
}

int	ft_close(t_cub *c)
{
	mlx_loop_end(c->mlx);
	if (c->mlx_win)
		mlx_destroy_window(c->mlx, c->mlx_win);
	if (c->img.img)
		mlx_destroy_image(c->mlx, c->img.img);
	if (c->notxt.img)
		mlx_destroy_image(c->mlx, c->notxt.img);
	if (c->sotxt.img)
		mlx_destroy_image(c->mlx, c->sotxt.img);
	if (c->eatxt.img)
		mlx_destroy_image(c->mlx, c->eatxt.img);
	if (c->wetxt.img != NULL)
		mlx_destroy_image(c->mlx, c->wetxt.img);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
	free_cub_data(c);
	exit(0);
	return (0);
}
