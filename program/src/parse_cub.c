/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:59:53 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/10 17:35:47 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_or_small_file(t_cub *file_data, t_list *list)
{
	file_data->line_nbr = ft_dlst_lstsize(list);
	if (!file_data->line_nbr)
	{
		file_data->err_msg = ft_strdup("Parsing error: cub file is empty: ");
		return (1);
	}
	if (file_data->line_nbr < 9)
	{
		file_data->err_msg = ft_strdup(
				"Parsing error: cub file doesn't contain enough info: ");
		return (1);
	}
	return (0);
}

int	copy_file(t_cub *file_data, int fd)
{
	char	*line;
	char	*cpy;

	file_data->raw_cpy = ft_dlst_init();
	if (!file_data->raw_cpy)
		ft_exit(file_data, "copy_file():", 12);
	line = get_next_line(fd);
	while (line != NULL)
	{
		cpy = ft_strdup(line);
		if (!cpy)
			ft_exit(file_data, "copy_file(): ", 12);
		ft_dlst_addlast(file_data->raw_cpy, cpy);
		free(line);
		line = get_next_line(fd);
	}
	if (empty_or_small_file(file_data, file_data->raw_cpy))
		return (0);
	return (1);
}

/*return 1 if read and copy the cubfile is success,
and all data is save in t_cub and checked for errors.
else return 0, which will go to ft_exit()*/
int	store_file_data(t_cub *file_data, char *cubfile)
{
	int	fd;

	fd = open(cubfile, O_RDONLY);
	if (fd < 0)
		ft_exit(file_data, "read_copy_file(): ", 2);
	if (!copy_file(file_data, fd))
		ft_exit(file_data, file_data->err_msg, 0);
	close(fd);
	if (!check_end(file_data, file_data->raw_cpy))
		ft_exit(file_data, file_data->err_msg, 0);
	if (!check_front(file_data, file_data->raw_cpy))
		ft_exit(file_data, file_data->err_msg, 0);
	if (!check_map(file_data, file_data->raw_cpy))
		ft_exit(file_data, file_data->err_msg, 0);
	if (!parse_txt(file_data))
		ft_exit(file_data, file_data->err_msg, 0);
	return (1);
}
