/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_delimitor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:09:13 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/11 12:48:01 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_has_delimitor(char *str, int c)
{
	size_t	count;

	if (!str)
		return (FALSE);
	count = 0;
	while (str && str[count])
	{
		if (str[count] == c)
			return (TRUE);
		count++;
	}
	return (FALSE);
}
