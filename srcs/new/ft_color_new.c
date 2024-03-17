/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:24:30 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 16:24:32 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_color	*ft_color_new(void)
{
	t_color	*new;

	new = (t_color *)malloc(sizeof(t_color));
	if (!new)
		return (NULL);
	ft_init_color(&new);
	return (new);
}
