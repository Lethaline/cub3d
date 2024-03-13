/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:13:09 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 13:47:31 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_input_name(char *filename)
{
	size_t	count;

	count = 0;
	if (!filename || !filename[0])
		return (FAIL);
	while (filename[count])
	{
		if (filename[count] == '.')
			break ;
		count++;
	}
	if (filename[count] == '\0')
		return (FAIL);
	if (ft_strncmp(&filename[count], ".cub", 4) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	ft_check_inputs(int ac, char **av)
{
	if (ac != 2)
		return (ft_print_error("Error\nBad number of args\n", FAIL));
	if (ft_check_input_name(av[1]) == FAIL)
		return (ft_print_error("Error\nBad filename\n", FAIL));
	if (ft_access(av[1]) == FAIL)
		return (ft_print_error("Error\nFile canno't be access\n", FAIL));
	return (SUCCESS);
}
