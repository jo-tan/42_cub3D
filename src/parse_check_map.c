/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:19 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/11 17:12:37 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_node	*ptr_to_map(t_list *list)
{
	t_node	*p;

	p = list->head->next;
	while (p != NULL)
	{
		if (is_empty(p->content))
			p = p->next;
		else if (is_map(p->content))
			break ;
		else
			p = p->next;
	}
	return (p);
}

char	*create_map_line(t_cub *file_data, char *content)
{
	int		j;
	char	*line;

	line = ft_calloc((file_data->map_w + 1), sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (content[j] != '\n' && content[j] != '\0')
	{
		line[j] = content[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

/*create_map
copy the map from list to array. Last array is NULL*/
char	**create_map(t_cub *file_data, t_node *first)
{
	char	**cpy;
	t_node	*p;
	int		i;

	cpy = malloc(sizeof(char *) * (file_data->map_h + 1));
	if (!cpy)
		ft_exit(file_data, "create_map(): ", 12);
	i = 0;
	p = first;
	while (p != NULL)
	{
		cpy[i] = create_map_line(file_data, p->content);
		if (!cpy[i])
		{
			free_array(cpy);
			ft_exit(file_data, "create_map(): ", 12);
		}
		i++;
		p = p->next;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	cpy_map(t_cub *file_data, t_node *first)
{
	char	**cpy;

	cpy = create_map(file_data, first);
	if (!valid_map(file_data, cpy))
	{
		free_array(cpy);
		return (0);
	}
	file_data->map = cpy;
	return (1);
}

int	check_map(t_cub *file_data, t_list *list)
{
	t_node	*p;

	p = ptr_to_map(list);
	if (find_map_empty_line(p))
	{
		file_data->err_msg = ft_strdup("Parsing error: map has empty line: ");
		if (!file_data->err_msg)
			ft_exit(file_data, "check_map(): ", 12);
		return (0);
	}
	tab_to_space(file_data, p);
	if (!update_map_data(file_data, p))
		return (0);
	if (!cpy_map(file_data, p))
		return (0);
	return (1);
}
