/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:22:33 by jo-tan            #+#    #+#             */
/*   Updated: 2023/11/13 18:22:34 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = (int)ft_strlen((const char *)s);
	while (len > 0)
	{
		write(fd, s++, 1);
		len--;
	}
	write(fd, "\n", 1);
}
