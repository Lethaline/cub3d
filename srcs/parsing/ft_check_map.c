/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:25:16 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/17 02:33:24 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_valide_char(char c, char *str)
{
	size_t	count;
	int		found;

	count = 0;
	found = 0;
	while (str && str[count])
	{
		if (c == str[count])
			found = 1;
		count++;
	}
	return (found);
}

int	ft_check_map(char *line)
{
	size_t	count;

	count = 0;
	if (!line)
		return (FALSE);
	while (line && line[count])
	{
		if (ft_valide_char(line[count], " 10NSWE\n") == FALSE)
			return (FALSE);
		count++;
	}
	return (TRUE);
}
