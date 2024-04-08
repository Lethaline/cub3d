/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:28 by cmartino          #+#    #+#             */
/*   Updated: 2024/04/08 19:16:53 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx(t_mlx **mlx)
{
	(*mlx)->mlx_p = NULL;
	(*mlx)->wind = NULL;
	(*mlx)->cub = NULL;
	(*mlx)->ray = ft_ray_new();
}