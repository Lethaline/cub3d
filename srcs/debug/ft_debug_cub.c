/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:13:50 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 17:13:50 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_debug_cub(t_cub *cub)
{
	printf("Cardinaux :\n");
	printf("NO : %s\n", cub->file->north);
	printf("SO : %s\n", cub->file->south);
	printf("WE : %s\n", cub->file->west);
	printf("EA : %s\n", cub->file->east);
	printf("Colors :\n");
	printf("Floor RED : %d\n", cub->file->floor->red);
	printf("Floor GREEN : %d\n", cub->file->floor->green);
	printf("Floor BLUE : %d\n", cub->file->floor->blue);
	printf("Cell RED : %d\n", cub->file->cell->red);
	printf("Cell GREEN : %d\n", cub->file->cell->green);
	printf("Cell BLUE : %d\n", cub->file->cell->blue);
}
