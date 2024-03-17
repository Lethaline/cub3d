/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:27:38 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/17 02:38:46 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_free_tab(char **tab)
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
	return (1);
}
