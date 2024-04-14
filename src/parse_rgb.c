/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:54:28 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/13 03:36:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*The string is freeed in convert_str_to_rgb*/
char	*save_rgb_info(t_cub *file_data, char *p, int *len)
{
	char	*ret;

	while (p[*len])
	{
		if (ft_isspace(p[*len]))
			break ;
		(*len)++;
	}
	ret = ft_strndup(p, *len);
	if (!ret)
		ft_exit(file_data, "save_rgb_info(): ", 12);
	return (ret);
}

int	check_rgb_char(char c, char *next, int *digit_count, int *comma_count)
{
	if (ft_isdigit(c))
	{
		(*digit_count)++;
		if (*digit_count > 3)
			return (0);
	}
	else if (c == ',')
	{
		if (*next == ','
			|| *next == '\0' || ft_isspace(*next))
			return (0);
		(*comma_count)++;
		*digit_count = 0;
	}
	else
		return (0);
	return (1);
}

/*Valid_rgb function:
1. will make sure the format of string is correct
2. the value will be checked when convert string to int*/
int	valid_rgb(char *tmp)
{
	int	comma_count;
	int	digit_count;
	int	i;

	comma_count = 0;
	digit_count = 0;
	i = 0;
	if (!ft_isdigit(tmp[0]))
		return (0);
	while (tmp[i])
	{
		if (!check_rgb_char(tmp[i], &tmp[i + 1], &digit_count, &comma_count))
			return (0);
		i++;
	}
	if (comma_count != 2)
		return (0);
	return (1);
}
