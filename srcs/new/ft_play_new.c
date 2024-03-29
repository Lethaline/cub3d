/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:11:49 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/29 12:05:41 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_play	*ft_play_new(size_t x, size_t y, double direction)
{
	t_play	*new;

	new = (t_play *)malloc(sizeof(t_play));
	if (!new)
		return (NULL);
	ft_init_play(&new);
	new->x = x;
	new->y = y;
	new->direction = direction;
	return (new);
}
