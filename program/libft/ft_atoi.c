/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:05 by jo-tan            #+#    #+#             */
/*   Updated: 2022/11/16 16:59:48 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg_sign;
	int	res;

	i = 0;
	neg_sign = 0;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg_sign = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = 10 * res + (nptr[i] - '0');
		i++;
	}
	if (neg_sign > 0)
		res *= -1;
	return (res);
}
