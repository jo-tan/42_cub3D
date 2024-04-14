/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:10 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 21:17:18 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pickdir_y(t_cub *c)
{
	if (c->plyr == 'N')
		return (-1);
	if (c->plyr == 'S')
		return (1);
	return (0);
}

int	pickdir_x(t_cub *c)
{
	if (c->plyr == 'E')
		return (1);
	if (c->plyr == 'W')
		return (-1);
	return (0);
}

void	init_ply(t_cub *c)
{
	c->move_up = 0;
	c->move_down = 0;
	c->move_left = 0;
	c->move_right = 0;
	c->pl.pos_x = c->p_x + 0.5;
	c->pl.pos_y = c->p_y + 0.5 - 1;
	c->pl.dir_x = pickdir_x(c);
	c->pl.dir_y = pickdir_y(c);
	if (c->plyr == 'N' || c->plyr == 'S')
	{
		if (c->plyr == 'S')
			c->plane_x = 0.66 * -1;
		else
			c->plane_x = 0.66 * 1;
		c->plane_y = 0;
	}
	else
	{
		c->plane_x = 0;
		if (c->plyr == 'E')
			c->plane_y = 0.66 * 1;
		else
			c->plane_y = 0.66 * -1;
	}
}

void	inittxt(t_cub *c, t_data *img, char *path)
{
	img->img = NULL;
	img->img = mlx_xpm_file_to_image(c->mlx, path, &img->width, &img->height);
	if (!img->img)
	{
		printf("Error\nXPM %s is invalid\n", path);
		return ;
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		printf("Error\nXPM %s is invalid\n", path);
}

void	ft_init_txt(t_cub *c)
{
	c->rot_left = 0;
	c->rot_right = 0;
	inittxt(c, &c->notxt, c->no_txt);
	inittxt(c, &c->sotxt, c->so_txt);
	inittxt(c, &c->eatxt, c->ea_txt);
	inittxt(c, &c->wetxt, c->we_txt);
	if (!c->notxt.img || !c->sotxt.img || !c->eatxt.img || !c->wetxt.img)
		txtinit_close(c);
}
