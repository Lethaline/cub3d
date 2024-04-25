/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:28 by cmartino          #+#    #+#             */
/*   Updated: 2024/04/24 02:51:52 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx(t_mlx **mlx)
{
	(*mlx)->mlx_ptr = NULL;
	(*mlx)->win_ptr = NULL;
	(*mlx)->img_ptr = NULL;
	(*mlx)->address = NULL;
	(*mlx)->cub = NULL;
	//(*mlx)->ray = ft_ray_new();
	//(*mlx)->player = ft_play_new();
}