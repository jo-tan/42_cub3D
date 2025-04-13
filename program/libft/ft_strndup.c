/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:11:07 by jo-tan            #+#    #+#             */
/*   Updated: 2023/07/06 04:49:39 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t i)
{
	char	*ptr;

	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, i);
	ptr[i] = '\0';
	return (ptr);
}
