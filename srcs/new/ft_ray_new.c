/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:11:51 by lolemmen          #+#    #+#             */
/*   Updated: 2024/04/08 19:12:49 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ray	*ft_ray_new(void)
{
	t_ray	*new;

	new = (t_ray *)malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	ft_init_ray(&new);
	return (new);
}