/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:27:38 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/27 09:50:10 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**ft_free_tab(char **tab)
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
	return (NULL);
}
