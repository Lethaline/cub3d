/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:44:17 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/07 02:08:57 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_key_pressed(int key_code, t_mlx *mlx)
{
	if (key_code == ESC)
	{
		ft_exit_program(mlx);
		exit(SUCCESS);
	}
	return (0);
}
