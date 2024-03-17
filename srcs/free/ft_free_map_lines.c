/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:59:23 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/17 01:05:18 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_map_lines(t_cub *cub)
{
	t_map	*next;

	if (cub && cub->map_lines)
	{
		while (cub->map_lines)
		{
			next = cub->map_lines->next;
			ft_free_ptr(cub->map_lines->line);
			ft_free_ptr(cub->map_lines);
			cub->map_lines = next;
		}
	}
}
