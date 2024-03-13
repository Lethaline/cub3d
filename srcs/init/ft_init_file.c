/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:21:31 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 14:33:25 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_file(t_file *file)
{
	t_color	floor;
	t_color	cell;

	ft_memset(&floor, 0, sizeof(t_color));
	ft_memset(&cell, 0, sizeof(t_color));
	file->north = -1;
	file->south = -1;
	file->west = -1;
	file->east = -1;
	ft_init_color(&floor);
	file->floor = &floor;
	ft_init_color(&cell);
	file->cell = &cell;
}
