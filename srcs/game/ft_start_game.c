/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:46:22 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/07 02:08:22 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_start_game(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3d");
	mlx_key_hook(mlx->win_ptr, ft_key_pressed, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, ft_red_cross, mlx);
	mlx_loop_hook (mlx->mlx_ptr, ft_loop_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
}
