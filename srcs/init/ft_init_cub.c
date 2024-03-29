/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:15:50 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/29 14:06:25 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ray	*ft_ray_new(void)
{
	t_ray	ray;

	ray.ray_angle = 0;
	ray.distance = 0;
	ray.flag = 0;

	return (&ray);
}

void	ft_init_cub(t_cub **cub)
{
	(*cub)->file = ft_file_new();
	(*cub)->map_lines = NULL;
	(*cub)->map = NULL;
	(*cub)->ray = ft_ray_new();
	(*cub)->player = NULL;
	(*cub)->input_fd = -1;
	(*cub)->width = 0;
	(*cub)->height = 0;
}
