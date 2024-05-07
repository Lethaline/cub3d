/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 05:32:22 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/07 02:12:07 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_img(t_mlx *mlx)
{
	int		endian;
	int		bits_per_pixel;
	int		size_line;
	char	*new_address;

	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	new_address = mlx_get_data_addr(mlx->img_ptr,
			&bits_per_pixel, &size_line, &endian);
	mlx->address = new_address;
}
