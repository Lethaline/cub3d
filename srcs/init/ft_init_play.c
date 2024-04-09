/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:13:09 by lethaline         #+#    #+#             */
/*   Updated: 2024/04/09 02:58:39 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_play(t_play **player)
{
	(*player)->x_in_pixs = -1;
	(*player)->y_in_pixs = -1;
	(*player)->angle = -1;
	(*player)->fov_in_rads = -1;
	(*player)->rotation = -1;
	(*player)->left_right = -1;
	(*player)->up_down = -1;
}
