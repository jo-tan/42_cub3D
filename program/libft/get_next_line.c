/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:53:19 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/02 09:18:52 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cut_line(char *tmp)
{
	unsigned int	i;
	char			*s;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		s[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		s[i] = tmp[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_save_rest(char *tmp)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (tmp[i])
		s[j++] = tmp[i++];
	s[j] = '\0';
	free(tmp);
	return (s);
}

static char	*ft_new_string(char *s)
{
	if (!s)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	return (s);
}

static char	*ft_read_and_save_all(int fd, char *tmp)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (!tmp)
		tmp = ft_new_string(tmp);
	read_bytes = 1;
	while (!ft_strchr(tmp, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		tmp = ft_gnl_strjoin(tmp, buff);
	}
	free(buff);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read_and_save_all(fd, tmp);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	line = ft_cut_line(tmp);
	tmp = ft_save_rest(tmp);
	return (line);
}
