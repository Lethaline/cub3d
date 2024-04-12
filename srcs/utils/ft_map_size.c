/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:33:10 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/29 13:16:35 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_map_size(t_map **map)
{
	size_t	count;
	t_map	*temp;

	count = 0;
	temp = *map;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
