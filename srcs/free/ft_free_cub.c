/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:05:49 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 17:05:50 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_cub(t_cub *cub)
{
	ft_free_ptr(cub->file->floor);
	ft_free_ptr(cub->file->cell);
	ft_free_ptr(cub->file->north);
	ft_free_ptr(cub->file->south);
	ft_free_ptr(cub->file->west);
	ft_free_ptr(cub->file->east);
	ft_free_ptr(cub->file);
	if (cub->input_fd != -1)
		close(cub->input_fd);
	ft_free_ptr(cub);
}
