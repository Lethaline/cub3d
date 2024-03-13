/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:58:07 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 00:33:17 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_atoi(const char *str)
{
	long	nb;
	int		minus;
	size_t	count;

	minus = 1;
	nb = 0;
	count = 0;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			minus *= -1;
		count++;
	}
	while (str[count] >= 48 && str[count] <= 57)
	{
		nb = nb * 10 + (str[count] - 48);
		if (nb * minus > 2147483647)
			return (-1);
		if (nb * minus < -2147483648)
			return (-1);
		count++;
	}
	if (str[count] != '\0')
		return (-1);
	return (nb * minus);
}
