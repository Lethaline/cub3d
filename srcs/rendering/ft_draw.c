/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 04:13:05 by lolemmen          #+#    #+#             */
/*   Updated: 2024/04/09 05:48:13 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_pixels(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	//mlx->address[x * 4 + y * WIDTH * 4] = color;
	//mlx->address[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	//mlx->address[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	//mlx->address[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
	return ;
}

int	ft_temp_get_color(t_mlx *mlx, int flag)
{
	mlx->ray->angle = ft_angle(mlx->ray->angle);
	if (flag == 0)
	{
		if (mlx->ray->angle > PI / 2 && mlx->ray->angle < 3 * (PI / 2))
			return (0xB5B5B5FF);
		else
			return (0xB5B5B5FF);
	}
	else
	{
		if (mlx->ray->angle > 0 && mlx->ray->angle < PI)
			return (0xF5F5F5FF);
		else
			return (0xF5F5F5FF);
	}
	return (-1);
}

void	ft_draw_floor(t_mlx *mlx, int ray, int top, int bottom)
{
	int	count;

	count = bottom;
	while (count < HEIGHT)
	{
		ft_put_pixels(mlx, ray, count, 0xB99470FF);
		count++;
	}
	count = 0;
	while (count < top)
	{
		ft_put_pixels(mlx, ray, count, 0x89CFF3FF);
		count++;
	}
	return ;
}

void	ft_draw_wall(t_mlx *mlx, int ray, int top, int bottom)
{
	int color;

	color = ft_temp_get_color(mlx, mlx->ray->flag);
	while (top < bottom)
	{
		ft_put_pixels(mlx, ray, top, color);
		top++;
	}
}

void	ft_render_wall(t_mlx *mlx, int ray)
{
	double	wall_height;
	double	bottom;
	double	top;

	mlx->ray->distance *= cos(ft_angle(mlx->ray->angle - mlx->player->angle));
	wall_height = (TILE_SIZE / mlx->ray->distance)
		* ((WIDTH / 2) / tan(mlx->player->fov_in_rads / 2));
	bottom = HEIGHT / 2 + wall_height / 2;
	top = HEIGHT / 2 - wall_height / 2;
	if (bottom > HEIGHT)
		bottom = HEIGHT;
	if (top < 0)
		top = 0;
	ft_draw_wall(mlx, ray, top, bottom);
	ft_draw_floor(mlx, ray, top, bottom);
	return ;
}