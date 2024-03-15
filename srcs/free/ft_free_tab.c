/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:27:38 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/15 00:27:35 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_int_tab(t_cub *cub)
{
	size_t	count;

	count = 0;
	while (cub && cub->map && cub->map[count])
	{
		free(cub->map[count]);
		count++;
	}
	free(cub->map);
}

void	ft_free_tab(char **tab)
{
	size_t	count;

	count = 0;
	if (tab)
	{
		while (tab && tab[count])
		{
			ft_free_ptr(tab[count]);
			count++;
		}
		ft_free_ptr(tab);
	}
}
