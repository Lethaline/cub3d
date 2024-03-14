/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:18:26 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/14 17:22:25 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map   *ft_map_new(void)
{
    t_map   *new;

    new = (t_map *)malloc(sizeof(t_map));
    if (!new)
        return (NULL);
    ft_init_map(&new);
    return (new);
}