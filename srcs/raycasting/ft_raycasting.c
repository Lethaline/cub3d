/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:30:59 by cmartino          #+#    #+#             */
/*   Updated: 2024/04/09 05:15:34 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_raycasting(t_mlx *mlx)
{
	double	horizontal;
	double	vertical;
	int	ray;

	ray = 0;
	mlx->ray->angle = mlx->player->angle - (mlx->player->fov_in_rads / 2);
	while (ray < WIDTH)
	{
		mlx->ray->flag = 0;
		horizontal = ft_get_horizontal(mlx, ft_angle(mlx->ray->angle));
		vertical = ft_get_vertical(mlx, ft_angle(mlx->ray->angle));
		if (vertical <= horizontal)
			mlx->ray->distance = vertical;
		else
		{
			mlx->ray->distance = horizontal;
			mlx->ray->flag = 1;
		}
		ft_render_wall(mlx, ray);
		ray++;
		mlx->ray->angle += (mlx->player->fov_in_rads / WIDTH);
	}
}
