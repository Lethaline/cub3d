/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:11:01 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/15 00:44:20 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_exit_program(t_cub *cub)
{
	ft_free_map_lines(&cub->map_lines);
	ft_free_int_tab(cub);
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