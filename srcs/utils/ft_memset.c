/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:57:22 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 13:58:44 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	count;
	char	*s1;

	count = 0;
	s1 = (char *)dest;
	while (count < len)
	{
		*(char *)s1 = (unsigned char)c;
		s1++;
		count++;
	}
	return (dest);
}
