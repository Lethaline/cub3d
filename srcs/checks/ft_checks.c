/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:13:09 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/11 17:14:45 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_inputs(int ac, char **av)
{
	if (ac != 2)
		return (ft_print_error("Error\nBad number of args\n", FAIL));
	if (ft_check_ext(av[1], ".cub") == FAIL)
		return (ft_print_error("Error\nBad filename\n", FAIL));
	if (ft_access(av[1]) == FAIL)
		return (ft_print_error("Error\nFile canno't be access\n", FAIL));
	return (SUCCESS);
}
