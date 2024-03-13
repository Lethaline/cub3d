/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:21:31 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 14:33:25 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_file(t_file **file)
{
	(*file)->north = NULL;
	(*file)->south = NULL;
	(*file)->west = NULL;
	(*file)->east = NULL;
	(*file)->floor = ft_color_new();
	(*file)->cell = ft_color_new();
}
