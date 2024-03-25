/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:28 by cmartino          #+#    #+#             */
/*   Updated: 2024/03/25 16:05:18 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx(t_mlx *mlx){
	mlx->mlx_p = mlx_init();
	mlx->wind = mlx_new_window(mlx->mlx_p, 500, 500, "Cub3d");
}