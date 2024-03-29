/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:15:43 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/29 13:17:13 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_map_height(t_map **map)
{
	size_t	count;
	size_t	height;
	t_map	*temp;

	count = 0;
	height = 0;
	temp = *map;
	while (temp)
	{
		if (height < ft_strlen(temp->line))
			height = ft_strlen(temp->line);
		count++;
		temp = temp->next;
	}
	return (height);
}