/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:00:13 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/27 10:07:39 by lolemmen         ###   ########.fr       */
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
    new->mlx_p = mlx_init();
    new->wind = mlx_new_window(new->mlx_p, 500, 500, "Cub3d");
    new->cub = cub;
    return (new);
}