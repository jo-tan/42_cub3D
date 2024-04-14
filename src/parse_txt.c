/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_txt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:53:05 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/05 19:56:05 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	report_err_txt(t_cub *file_data, char *path)
{
	if (file_data->err_msg != NULL)
		free(file_data->err_msg);
	file_data->err_msg = ft_strjoin("TXT file error: invalid file: ", path);
	if (!file_data->err_msg)
		ft_exit(file_data, "report_err_txt(): ", 12);
}

int	isxpm(char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	is_valid_xpm(t_cub *file_data)
{
	if (!isxpm(file_data->no_txt))
		return (report_err_txt(file_data, file_data->no_txt), 0);
	if (!isxpm(file_data->so_txt))
		return (report_err_txt(file_data, file_data->so_txt), 0);
	if (!isxpm(file_data->ea_txt))
		return (report_err_txt(file_data, file_data->ea_txt), 0);
	if (!isxpm(file_data->we_txt))
		return (report_err_txt(file_data, file_data->we_txt), 0);
	return (1);
}

int	parse_txt(t_cub *file_data)
{
	if (!is_valid_xpm(file_data))
		return (0);
	return (1);
}
