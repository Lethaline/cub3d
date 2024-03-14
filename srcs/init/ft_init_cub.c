/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:15:50 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 16:20:41 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_cub(t_cub **cub)
{
	(*cub)->file = ft_file_new();
	(*cub)->map_lines = NULL;
	(*cub)->input_fd = -1;
}
