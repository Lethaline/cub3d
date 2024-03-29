/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:57:21 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/29 12:12:15 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_map_add_back(t_map **map, t_map *new)
{
	t_map	*temp;

	if (!map || !new)
		return ;
	if (!*map)
		*map = new;
	else if (map && *map)
	{
		temp = *map;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->previous = temp;
	}
}
