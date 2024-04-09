/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 03:06:05 by lolemmen          #+#    #+#             */
/*   Updated: 2024/04/09 05:20:05 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_circle(float angle, int direction)
{
	if (direction == HORIZONTAL)
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (direction == VERTICAL)
	{
		if (angle > (PI / 2) && angle < (3 * PI) / 2)
			return (1);
	}
	return (0);
}

int	ft_wall(float x, float y, t_mlx *mlx)
{
	int	x_position;
	int	y_position;

	if (x < 0 || y < 0)
		return (0);
	x_position = floor(x / TILE_SIZE);
	y_position = floor(y / TILE_SIZE);
	if ((y_position >= mlx->cub->height || x_position >= mlx->cub->width))
		return (0);
	if (mlx->cub->map[y_position]
		&& x_position <= ft_strlen(mlx->cub->map[y_position]))
	{
		if (mlx->cub->map[y_position][x_position]
			&& mlx->cub->map[y_position][x_position] == WALL)
			return (0);
	}
	return (1);
}

int	ft_check_intersection(float angle, float *sens, float *step, int direction)
{
	if (direction == HORIZONTAL)
	{
		if (angle > 0 && angle < PI)
		{
			*sens += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*sens += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

float	ft_get_vertical(t_mlx *mlx, float angle)
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE / tan(angle);
	x = floor(mlx->player->x_in_pixs / TILE_SIZE) * TILE_SIZE;
	pixel = ft_check_intersection(angle, &x, &x_step, VERTICAL);
	y = mlx->player->y_in_pixs + (x - mlx->player->x_in_pixs) * tan(angle);
	if ((ft_circle(angle, HORIZONTAL) && y_step < 0)
		|| (!ft_circle(angle, HORIZONTAL) && y_step > 0))
		y_step *= -1;
	while (ft_wall(x - pixel, y, mlx))
	{
		x += x_step;
		y += y_step;
	}
	return (sqrt(pow(x - mlx->player->x_in_pixs, 2)
		+ pow(y - mlx->player->y_in_pixs, 2)));
}

float	ft_get_horizontal(t_mlx *mlx, float angle)
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE * tan(angle);
	y_step = TILE_SIZE;
	y = floor(mlx->player->y_in_pixs / TILE_SIZE) * TILE_SIZE;
	pixel = ft_check_intersection(angle, &y, &y_step, HORIZONTAL);
	x = mlx->player->x_in_pixs + (y - mlx->player->y_in_pixs) / tan(angle);
	if ((ft_circle(angle, VERTICAL) && x_step > 0)
		|| (!ft_circle(angle, VERTICAL) && x_step < 0))
		x_step *= -1;
	while (ft_wall(x, y - pixel, mlx))
	{
		x += x_step;
		y += y_step;
	}
	return (sqrt(pow(x - mlx->player->x_in_pixs, 2)
		+ pow(y - mlx->player->y_in_pixs, 2)));
}