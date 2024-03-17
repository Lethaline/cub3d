/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:54:08 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/12 23:55:01 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_tablen(char **tab)
{
	size_t	count;

	count = 0;
	while (tab && tab[count])
		count++;
	return (count);
}
