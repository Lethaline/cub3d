/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:03:12 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 14:30:20 by lolemmen         ###   ########.fr       */
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
	return (SUCCESS);
}
