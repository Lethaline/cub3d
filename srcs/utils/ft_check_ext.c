/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:44:51 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/11 17:15:53 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_ext(char *path, char *extension)
{
	size_t	count;

	if (!path || !path[0] || !extension || !extension[0])
		return (FAIL);
	count = ft_strlen(path);
	while (count > 0)
	{
		if (path[count] == '.')
			break ;
		count--;
	}
	if (path[count] == '\0')
		return (FAIL);
	if (ft_strncmp(&path[count], extension, 4) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
