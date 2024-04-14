/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:11:39 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 09:52:53 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	iscub(char *file)
{
	int	len;

	if (file == NULL)
		return (0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_exit(NULL, "HINT: ./cub3D <map>.cub: ", 22);
	if (iscub(av[1]) == 0)
		ft_exit(NULL, "HINT: <map>.cub: ", 22);
	init(av[1]);
	return (0);
}
