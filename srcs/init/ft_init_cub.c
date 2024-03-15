/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:15:50 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/15 00:43:43 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_cub(t_cub **cub)
{
	(*cub)->file = ft_file_new();
	(*cub)->map_lines = NULL;
	(*cub)->map = 0;
	(*cub)->input_fd = -1;
}
