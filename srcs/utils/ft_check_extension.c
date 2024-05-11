/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:44:51 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/11 16:58:37 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_xpm(char *sprite)
{
	size_t	count;

	if (!sprite || !sprite[0])
		return (FAIL);
	count = ft_strlen(sprite);
	while (count > 0)
	{
		if (sprite[count] == '.')
			break ;
		count--;
	}
	if (sprite[count] == '\0')
		return (FAIL);
	if (ft_strncmp(&sprite[count], ".xpm", 4) == FAIL)
		return (FAIL);
	return (SUCCESS);
}