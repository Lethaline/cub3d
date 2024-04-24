/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:00:13 by lolemmen          #+#    #+#             */
/*   Updated: 2024/04/24 02:52:16 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mlx   *ft_mlx_new(t_cub *cub)
{
    t_mlx   *new;

    new = (t_mlx *)malloc(sizeof(t_mlx));
    if (!new)
        return (NULL);
    ft_init_mlx(&new);
    new->cub = cub;
   // new->player->x_in_pixs = cub->x * TILE_SIZE + TILE_SIZE / 2;
    //new->player->y_in_pixs = cub->y * TILE_SIZE + TILE_SIZE / 2;
    //new->player->angle = cub->direction;
    //new->player->fov_in_rads = FOV * PI / 180;
    return (new);
}