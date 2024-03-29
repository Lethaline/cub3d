/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:19:06 by cmartino          #+#    #+#             */
/*   Updated: 2024/03/29 14:25:17 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_fov(double c_view)
{
	double	l_view;

	l_view = c_view - (PI / 6);
	if (l_view < 0)
		l_view = (11 * PI) / 6;
	if (l_view > (2 * PI))
		l_view = PI / 6;
	return (l_view);
}
