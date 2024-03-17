/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:17:20 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 21:18:33 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
