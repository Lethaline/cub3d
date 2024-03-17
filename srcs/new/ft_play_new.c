/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:11:49 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/17 02:32:28 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_play	*ft_play_new(int x, int y, char direction)
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
