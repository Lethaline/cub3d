/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:30:59 by cmartino          #+#    #+#             */
/*   Updated: 2024/03/29 15:03:24 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
