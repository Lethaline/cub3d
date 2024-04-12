/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:11:01 by lethaline         #+#    #+#             */
/*   Updated: 2024/04/09 02:37:51 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_exit_program(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->mlx_ptr && mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_free_cub(mlx->cub);
		ft_free_ptr(mlx->ray);
		ft_free_ptr(mlx);
	}
	return (1);
}
