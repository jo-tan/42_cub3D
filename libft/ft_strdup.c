/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:16:27 by jo-tan            #+#    #+#             */
/*   Updated: 2023/11/13 18:16:29 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*ptr;
	size_t		s_len;
	size_t		i;

	i = 0;
	s_len = ft_strlen(s);
	ptr = (char *)malloc((s_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < s_len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
