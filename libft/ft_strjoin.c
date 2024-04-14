/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:19:40 by jo-tan            #+#    #+#             */
/*   Updated: 2023/11/28 16:18:13 by aauthier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	l;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	l = (unsigned int)ft_strlen(s1) + (unsigned int)ft_strlen(s2);
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
	return (res);
}
