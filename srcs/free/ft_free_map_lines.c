/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:59:23 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/15 01:09:17 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_free_map(t_map *map)
{
	ft_free_ptr(map->line);
	ft_free_ptr(map);
}

void	ft_free_map_lines(t_map **map)
{
	t_map	*next;

	while (*map)
	{
		next = (*map)->next;
		ft_free_map(*map);
		*map = next;
	}
}