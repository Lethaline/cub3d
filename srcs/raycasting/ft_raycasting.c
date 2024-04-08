/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:30:59 by cmartino          #+#    #+#             */
/*   Updated: 2024/04/08 19:47:34 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_raycasting(t_mlx *mlx)
{
	int	ray;

	ray = 0;
	mlx->cub->ray->ray_angle = ft_fov(mlx->cub->player->direction);
	while (ray < WIDTH)
	{
		ft_get_intersections(mlx);
		ray++;
	}
}
