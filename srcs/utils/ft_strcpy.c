/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:15:40 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/11 18:17:26 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strcpy(char *src, int n)
{
	char	*dest;

	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[n] = '\0';
	n--;
	while (n >= 0)
	{
		dest[n] = src[n];
		n--;
	}
	return (dest);
}
