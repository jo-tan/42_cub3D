/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:49:54 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/05 17:19:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*free char array. Assume the pointer to array is never pointed to NULL
but it is posible that the array is empty*/
void	free_array(char **arr)
{
	char	**p;

	p = arr;
	if (*arr != NULL)
	{
		while (*arr)
		{
			free(*arr);
			++arr;
		}
	}
	free(p);
}

/*if t_cub holds any information of cub file, 
free anything which has allocated memory with malloc.
Last, free the pointer of t_cub*/
void	free_cub_data(t_cub *file_data)
{
	if (file_data->raw_cpy != NULL)
		ft_dlst_freelst(file_data->raw_cpy);
	if (file_data->err_msg != NULL)
		free(file_data->err_msg);
	if (file_data->no_txt != NULL)
		free(file_data->no_txt);
	if (file_data->so_txt != NULL)
		free(file_data->so_txt);
	if (file_data->ea_txt != NULL)
		free(file_data->ea_txt);
	if (file_data->we_txt != NULL)
		free(file_data->we_txt);
	if (file_data->map != NULL)
		free_array(file_data->map);
	free(file_data);
}

void	ft_exit(t_cub *file_data, char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("Error", 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd("cub3D: ", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errnum != 0)
		ft_putendl_fd(strerror(errnum), 2);
	if (!errnum)
		ft_putchar_fd('\n', 2);
	if (file_data != NULL)
		free_cub_data(file_data);
	exit(1);
}

void	print_map(char **map)
{
	char	**p;

	p = map;
	while (*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
}

void	print_cub_data(t_cub *file_data)
{
	printf("***check the raw_cpy***\n");
	ft_dlst_printlst(file_data->raw_cpy);
	printf("\n***END of raw_cpy***\n");
	printf("===check t_cub data===\n");
	printf("file_data->plyr: %c\n", file_data->plyr);
	printf("file_data->p_x: %i\n", file_data->p_x);
	printf("file_data->p_y: %i\n", file_data->p_y);
	printf("file_data->no_txt: %s\n", file_data->no_txt);
	printf("file_data->so_txt: %s\n", file_data->so_txt);
	printf("file_data->ea_txt: %s\n", file_data->ea_txt);
	printf("file_data->we_txt: %s\n", file_data->we_txt);
	printf("file_data->f_rgb: 0x%06X\n", file_data->f_rgb);
	printf("file_data->c_rgb: 0x%06X\n", file_data->c_rgb);
	printf("file_data->map_w: %i\n", file_data->map_w);
	printf("file_data->map_h: %i\n", file_data->map_h);
	printf("+++FINAL MAP COPY+++\n");
	print_map(file_data->map);
	printf("===END CHECK===\n");
}
