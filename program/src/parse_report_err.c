/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_report_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:02:06 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 03:06:27 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	report_err_line(t_cub *file_data, int line_nbr)
{
	char	*err_tmp;
	char	*nbr_tmp;

	if (file_data->err_msg != NULL)
		free(file_data->err_msg);
	nbr_tmp = ft_itoa(line_nbr);
	err_tmp = ft_strjoin("Parsing error: cub file line ", nbr_tmp);
	if (!err_tmp)
		ft_exit(file_data, "report_err_line(): ", 12);
	file_data->err_msg = ft_strjoin(err_tmp,
			" missing map or contains invalid data: ");
	if (!file_data->err_msg)
	{
		free(err_tmp);
		free(nbr_tmp);
		ft_exit(file_data, "report_err_line(): ", 12);
	}
	free(err_tmp);
	free(nbr_tmp);
}

void	report_err_plyr(t_cub *file_data, int line_nbr)
{
	char	*err_tmp;
	char	*nbr_tmp;

	if (file_data->err_msg != NULL)
		free(file_data->err_msg);
	nbr_tmp = ft_itoa(line_nbr);
	err_tmp = ft_strjoin("Parsing error: map line ", nbr_tmp);
	if (!err_tmp)
		ft_exit(file_data, "report_err_plyr(): ", 12);
	file_data->err_msg = ft_strjoin(err_tmp, " find multuple player: ");
	if (!file_data->err_msg)
	{
		free(err_tmp);
		ft_exit(file_data, "report_err_plyr(): ", 12);
	}
	free(err_tmp);
	free(nbr_tmp);
}

void	report_err_map(t_cub *file_data, int line_nbr)
{
	char	*err_tmp;
	char	*nbr_tmp;

	if (file_data->err_msg != NULL)
		free(file_data->err_msg);
	nbr_tmp = ft_itoa(line_nbr + 1);
	err_tmp = ft_strjoin("Parsing error: map line ", nbr_tmp);
	if (!err_tmp)
		ft_exit(file_data, "report_err_map(): ", 12);
	file_data->err_msg = ft_strjoin(err_tmp,
			" find invalid character: ");
	if (!file_data->err_msg)
	{
		free(err_tmp);
		ft_exit(file_data, "report_err_map(): ", 12);
	}
	free(err_tmp);
	free(nbr_tmp);
}

void	report_err_path(t_cub *file_data, int line_nbr)
{
	char	*err_tmp;
	char	*nbr_tmp;

	if (file_data->err_msg != NULL)
		free(file_data->err_msg);
	nbr_tmp = ft_itoa(line_nbr);
	err_tmp = ft_strjoin("Map error: map line ", nbr_tmp);
	if (!err_tmp)
		ft_exit(file_data, "report_err_path(): ", 12);
	file_data->err_msg = ft_strjoin(err_tmp, " can't be access by player: ");
	if (!file_data->err_msg)
	{
		free(err_tmp);
		ft_exit(file_data, "report_err_path(): ", 12);
	}
	free(err_tmp);
	free(nbr_tmp);
}
