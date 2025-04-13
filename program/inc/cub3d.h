/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:32:51 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 21:27:35 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include <mlx.h>
# include </usr/include/X11/X.h>

# define SW 960
# define SH 540
# define FOV 70
# define TILE_SIZE 32
# define PL_SPEED 0.03
# define ROT_SPEED 0.018
# define PI_C 3.141592653589793
# define KLEFT 65361
# define  KRIGHT 65363
//   KUP 65363
//   KDOWN 65364
# define KEYA 97
# define KEYD 100
# define KUP 119
# define KDOWN 115
# define ESCAPE 65307

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_ray
{
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	perp_walldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
}	t_ray;

typedef struct s_pl {
	int		map_x;
	int		map_y;
	double	cam_x;
	double	cam_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_pl;

/*information from cub file*/
typedef struct s_cub
{
	t_list	*raw_cpy;
	char	*err_msg;
	int		line_nbr;
	char	plyr;
	int		p_x;
	int		p_y;
	char	*no_txt;
	t_data	notxt;
	char	*so_txt;
	t_data	sotxt;
	char	*ea_txt;
	t_data	eatxt;
	char	*we_txt;
	t_data	wetxt;
	int		f_rgb;
	int		c_rgb;
	char	**map;
	int		map_w;
	int		map_h;

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	double	ct;
	double	ot;
	double	plane_x;
	double	plane_y;
	double	old_dirx;
	double	old_planex;

	int		r_x;
	int		r_y;
	int		offset;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		color;
	t_data	*tex;

	t_pl	pl;
	t_ray	r;

	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rot_left;
	int		rot_right;
}	t_cub;

/*parse_init.c*/
void	init_txt(t_data *txt);
void	init(char *cubfile);
void	init_cub_info(t_cub *file_data);
/*parse_cub.c*/
int		empty_or_small_file(t_cub *file_data, t_list *list);
int		copy_file(t_cub *file_data, int fd);
int		store_file_data(t_cub *file_data, char *cubfile);
/*parse_check_end.c*/
int		is_map(char *line);
int		is_empty(char *line);
int		check_end(t_cub *file_data, t_list *list);
void	report_err_line(t_cub *file_data, int line_nbr);
/*parse_path.c*/
int		move_ptr_to_info_one(char *line);
void	store_path_info(t_cub *file_data, char **txt, char *line);
void	store_info(t_cub *file_data, char *line);
int		is_right_info(char *line);
/*parse_rgb.c*/
char	*save_rgb_info(t_cub *file_data, char *p, int *len);
int		valid_rgb(char *tmp);
/*parse_rgb2.c*/
void	convert_str_to_rgb(t_cub *file_data, char *tmp, int *rgb);
void	store_rgb_info(t_cub *file_data, int *rgb, char *line);
/*parse_check_front.c*/
int		check_front(t_cub *file_data, t_list *list);
/*parse_update_map_data.c*/
int		valid_map_line(char *line);
int		find_plyr(t_cub *file_data, char *line);
int		update_map_data(t_cub *file_data, t_node *first_node);
/*parse_valid_map.c*/
int		is_wall(char *line);
int		check_all_sides(char **pos, int j);
int		is_surround(char **pos);
int		valid_map(t_cub *file_data, char **map);
/*parse_valid_path.c*/
int		find_map_empty_line(t_node *p);
int		check_space_in_map(char *line);
void	move_on_paths(int x, int y, char **map_cpy);
char	**duplicate_array(t_cub *file_data, char **array);
int		valid_path(t_cub *file_data);
/*parse_check_map.c*/
int		check_map(t_cub *file_data, t_list *list);
/*parse_tab_to_space.c*/
int		find_tab(char *line, int n_tab);
int		update_tab_to_space(char **line, int n_tab);
void	tab_to_space(t_cub *file_data, t_node *first);
/*parse_txt.c*/
int		parse_txt(t_cub *file_data);
/*parse_report_err.c*/
void	report_err_line(t_cub *file_data, int line_nbr);
void	report_err_plyr(t_cub *file_data, int line_nbr);
void	report_err_map(t_cub *file_data, int line_nbr);
void	report_err_path(t_cub *file_data, int line_nbr);
/*free.c*/
void	free_array(char **arr);
void	free_cub_data(t_cub *file_data);
void	ft_exit(t_cub *file_data, char *errmsg, int errnum);
void	print_cub_data(t_cub *file_data);
/*game.c*/
void	game(t_cub *c);
void	raycast(t_cub *c);
/*game_init.c*/
void	init_ply(t_cub *c);
void	ft_init_txt(t_cub *c);
/*game_color.c*/
void	safe_mlx_pixel_put(t_cub *c, int x, int y, int color);
int		get_pixel_color(t_data *data, int x, int y);
/*game_raycast.c*/
void	part1(t_cub *c);
void	part2(t_cub *c);
void	part3(t_cub *c);
void	part4(t_cub *c);
void	part5(t_cub *c);
/*game_loop.c*/
void	loop(t_cub *c);
/*game_move.c*/
void	rerender(t_cub *c);
int		move_up(t_cub *c);
int		move_down(t_cub *c);
int		move_left(t_cub *c);
int		move_right(t_cub *c);
/*game_close.c*/
int		txtinit_close(t_cub *c);
int		ft_close(t_cub *c);
/*gmae_rot.c*/
int		rot_right(t_cub *c);
int		rot_left(t_cub *c);

#endif
