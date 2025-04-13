/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tab_to_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:07:53 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 21:10:42 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_tab(char *line, int n_tab)
{
	while (*line)
	{
		if (*line == '\t')
			n_tab++;
		line++;
	}
	return (n_tab);
}

char	*update(char *line, int n_tab)
{
	char	*tmp;
	char	*p;
	char	*p_t;
	int		len;

	len = ft_strlen(line);
	tmp = malloc(sizeof(char) * (len + (n_tab * 3) + 1));
	if (!tmp)
		return (NULL);
	p = line;
	p_t = tmp;
	while (*p)
	{
		len = 0;
		if (*p == '\t')
		{
			while (len++ < 4)
				*p_t++ = ' ';
		}
		else
			*p_t++ = *p;
		p++;
	}
	*p_t = '\0';
	return (tmp);
}

int	update_tab_to_space(char **line, int n_tab)
{
	char	*tmp;

	tmp = update(*line, n_tab);
	free(*line);
	*line = tmp;
	return (1);
}

void	tab_to_space(t_cub *file_data, t_node *first)
{
	t_node	*p;
	int		n_tab;

	p = first;
	while (p != NULL)
	{
		n_tab = 0;
		if (find_tab(p->content, n_tab))
		{
			if (!update_tab_to_space(&(p->content), n_tab))
				ft_exit(file_data, "tab_to_space(): ", 12);
		}
		p = p->next;
	}
}
