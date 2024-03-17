/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:20:32 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 17:20:32 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_access(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (SUCCESS);
	}
	return (FAIL);
}
