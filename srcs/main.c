/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:03:12 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/15 00:20:09 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	*cub;
	int		fd;

	if (ft_check_inputs(ac, av) == FAIL)
		return (FAIL);
	cub = ft_cub_new(av[1]);
	if (ft_parsing(cub) == FAIL)
		return (FAIL);
	ft_exit_program(cub);
	return (SUCCESS);
}
