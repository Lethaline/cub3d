/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:20:25 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 01:08:58 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_check_color(t_color *color)
{
	if (color->red == -1 || color->green == -1 || color->blue == -1)
		return (FALSE);
	return (TRUE);
}

int	ft_check_scene(t_file *file)
{
	if (file->north == -1 || file->south == -1 || file->east == -1
		|| file->west == -1)
		return (FALSE);
	if (!ft_check_color(file->floor) || !ft_check_color(file->cell))
		return (FALSE);
	return (TRUE);
}
