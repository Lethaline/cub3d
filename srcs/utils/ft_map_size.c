/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:33:10 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/17 02:30:39 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_map_size(t_map *map)
{
	size_t	count;

	count = 0;
	while (map)
	{
		count++;
		map = map->next;
	}
	return (count);
}
