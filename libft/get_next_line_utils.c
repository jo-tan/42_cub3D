/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:56:27 by jo-tan            #+#    #+#             */
/*   Updated: 2023/02/15 06:23:23 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char			*res;
	size_t			i;
	size_t			l;

	i = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	l = 0;
	while (s2[l])
	{
		res[i + l] = s2[l];
		l++;
	}
	res[i + l] = '\0';
	free(s1);
	return (res);
}
