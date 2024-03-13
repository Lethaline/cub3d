/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:15:50 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 14:31:35 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_cub(t_cub *cub)
{
	t_file	file;

	ft_memset(&file, 0, sizeof(t_file));
	ft_init_file(&file);
	cub->file = &file;
}
