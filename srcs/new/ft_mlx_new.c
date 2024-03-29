/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:00:13 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/29 11:25:56 by cmartino         ###   ########.fr       */
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
    new->wind = mlx_new_window(new->mlx_p, WIDTH, HEIGHT, "Cub3d");
    new->cub = cub;
    return (new);
}