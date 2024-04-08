/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:47 by lethaline         #+#    #+#             */
/*   Updated: 2024/04/08 19:22:51 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_file(t_file **file)
{
	if (*file)
	{
		ft_free_ptr((*file)->north);
		ft_free_ptr((*file)->south);
		ft_free_ptr((*file)->west);
		ft_free_ptr((*file)->east);
		ft_free_ptr((*file)->floor);
		ft_free_ptr((*file)->cell);
		ft_free_ptr((*file));
	}
}

void	ft_free_cub(t_cub *cub)
{
	if (cub)
	{
		ft_free_file(&cub->file);
		ft_free_map_lines(cub);
		ft_free_tab(cub->map);
		if (cub->input_fd != -1)
			close(cub->input_fd);
		ft_free_ptr(cub);
	}
}
