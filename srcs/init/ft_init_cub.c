/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:15:50 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/29 13:15:41 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_cub(t_cub **cub)
{
	(*cub)->file = ft_file_new();
	(*cub)->map_lines = NULL;
	(*cub)->map = NULL;
	(*cub)->player = NULL;
	(*cub)->input_fd = -1;
	(*cub)->width = 0;
	(*cub)->height = 0;
}
