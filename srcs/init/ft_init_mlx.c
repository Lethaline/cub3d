/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:28 by cmartino          #+#    #+#             */
/*   Updated: 2024/05/07 02:12:18 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx(t_mlx **mlx)
{
	(*mlx)->mlx_ptr = NULL;
	(*mlx)->win_ptr = NULL;
	(*mlx)->img_ptr = NULL;
	(*mlx)->address = NULL;
	(*mlx)->cub = NULL;
}
