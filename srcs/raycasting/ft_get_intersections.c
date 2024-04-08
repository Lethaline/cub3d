/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_intersections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:34:42 by cmartino          #+#    #+#             */
/*   Updated: 2024/03/29 15:15:02 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_get_h_inter(t_mlx *mlx)
{
	return (1);
}

double	ft_get_v_inter(t_mlx *mlx)
{
	
	return (1);
}

void	ft_get_intersections(t_mlx *mlx)
{
	double	h_inter;
	double	v_inter;

	h_inter = ft_get_h_inter(mlx);
	v_inter = ft_get_v_inter(mlx);
	if (v_inter < h_inter)
	{
		mlx->cub->ray->distance = v_inter;
		mlx->cub->ray->flag = 1;
	}
	else
	{
		mlx->cub->ray->distance = h_inter;
		mlx->cub->ray->flag = 0;
	}
}