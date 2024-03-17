/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:15:39 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 21:17:03 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_bzero(void *s, size_t size)
{
	char	*str;
	size_t	count;

	str = (char *)s;
	count = 0;
	while (count < size)
	{
		str[count] = '\0';
		count++;
	}
}
