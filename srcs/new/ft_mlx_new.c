/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:16:48 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/07 02:19:02 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mlx	*ft_mlx_new(t_cub *cub)
{
	t_mlx	*new;

	new = (t_mlx *)malloc(sizeof(t_mlx));
	if (!new)
		return (NULL);
	ft_init_mlx(&new);
	new->cub = cub;
	return (new);
}
